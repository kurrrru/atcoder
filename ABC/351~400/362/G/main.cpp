#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace toolbox
{

namespace string
{

namespace helper
{

std::vector<int> sais(const std::vector<int> &s, const int max_s);

/**
* @brief Computes the suffix array of a given string using the doubling algorithm.
* @param s The string for which to compute the suffix array.
* @return A suffix array for the given string.
* @note [Complexity]: O(n log n)
*/
std::vector<int> suffixarray_doubling(const std::vector<int> &s)
{
	int n = s.size();
	std::vector<int> SA(n), ISA(n), nextISA(n);

	std::iota(SA.begin(), SA.end(), 0);
	std::sort(SA.begin(), SA.end(), [&](int i, int j) {return s[i] < s[j];});
	ISA[SA[0]] = 0;
	for (int i = 1; i < n; i++)
		ISA[SA[i]] = ISA[SA[i - 1]] + (s[SA[i - 1]] != s[SA[i]]);
	for (int k = 1; k < n; k *= 2)
	{
		auto cmp = [&](int i, int j)
		{
			if (ISA[i] != ISA[j])
				return ISA[i] < ISA[j];
			int rank_i = i + k < n ? ISA[i + k] : -1;
			int rank_j = j + k < n ? ISA[j + k] : -1;
			return rank_i < rank_j;
		};
		int start = 0;
		while (start < n)
		{
			int end = start + 1;
			while (end < n && ISA[SA[start]] == ISA[SA[end]])
				end++;
			if (end - start > 1)
				std::sort(SA.begin() + start, SA.begin() + end, cmp);
			start = end;
		}
		nextISA[SA[0]] = 0;
		for (int i = 1; i < n; i++)
			nextISA[SA[i]] = nextISA[SA[i - 1]] + cmp(SA[i - 1], SA[i]);
		std::swap(ISA, nextISA);
	}
	return SA;
}

/**
* @brief helper function for the suffix array induced sorting algorithm.
* Classifies the S-type and L-type characters of a given string.
* @param s The string for which to classify the S and L characters.
* @param ls The array to store the classification of S-type or L-type.
* @note [Complexity]: O(n)
* @note [Attention]: This function is not intended to be used directly.
*/
void sais_classify_sl(const std::vector<int> &s, std::vector<bool> &ls)
{
	int n = s.size();
	ls[n - 1] = false;
	for (int i = n - 2; i >= 0; i--)
	{
		if (s[i] == s[i + 1])
			ls[i] = ls[i + 1];
		else
			ls[i] = s[i] < s[i + 1];
	}
}

/**
* @brief helper function for the suffix array induced sorting algorithm.
* Counts the number of S-type and L-type characters in a given string.
* @param s The string for which to count the S and L characters.
* @param cnt_l The array to store the count of L-type characters.
* @param cnt_s The array to store the count of S-type characters.
* @param ls The array that stores the classification of S-type or L-type.
* @param max_s The maximum value of the characters in the string.
* @note [Complexity]: O(n)
* @note [Attention]: This function is not intended to be used directly.
*/
void sais_character_count(const std::vector<int> &s, std::vector<int> &cnt_l, std::vector<int> &cnt_s,
		const std::vector<bool> &ls, const int max_s)
{
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (!ls[i])
			cnt_s[s[i]]++;
		else
			cnt_l[s[i] + 1]++;
	}
	for (int i = 0; i <= max_s; i++)
	{
		cnt_s[i] += cnt_l[i];
		if (i < max_s)
			cnt_l[i + 1] += cnt_s[i];
	}
}

/**
* @brief helper function for the suffix array induced sorting algorithm.
* Searches for the LMS substrings in a given string.
* @param n The size of the string.
* @param ls The array that stores the classification of S-type or L-type.
* @param lms_map The array to store the mapping of LMS substrings.
* @param lms The array to store the LMS substrings.
* @note [Complexity]: O(n)
* @note [Attention]: This function is not intended to be used directly.
*/
void sais_search_lms(const int n, const std::vector<bool> &ls, std::vector<int> &lms_map, std::vector<int> &lms)
{
	int m = 0;
	for (int i = 1; i < n; i++)
	{
		if (!ls[i - 1] && ls[i])
		{
			lms_map[i] = m++;
			lms.push_back(i);
		}
	}
}

/**
* @brief helper function for the suffix array induced sorting algorithm.
* Induces the suffix array of a given string.
* @param s The string for which to induce the suffix array.
* @param sa The array to store the suffix array.
* @param cnt_l The array that stores the count of L-type characters.
* @param cnt_s The array that stores the count of S-type characters.
* @param ls The array that stores the classification of S-type or L-type.
* @param lms The array that stores the LMS substrings.
* @note [Complexity]: O(n)
* @note [Attention]: This function is not intended to be used directly.
*/
void sais_induce(const std::vector<int> &s, std::vector<int> &sa, const std::vector<int> &cnt_l,
		const std::vector<int> &cnt_s, const std::vector<bool> &ls, const std::vector<int> &lms)
{
	int n = s.size();
	std::fill(sa.begin(), sa.end(), -1);
	std::vector<int> buf = cnt_s;
	for (auto d : lms)
	{
		if (d == n)
			continue;
		sa[buf[s[d]]++] = d;
	}
	buf = cnt_l;
	sa[buf[s[n - 1]]++] = n - 1;
	for (int i = 0; i < n; i++)
		if (sa[i] >= 1 && !ls[sa[i] - 1])
			sa[buf[s[sa[i] - 1]]++] = sa[i] - 1;
	buf = cnt_l;
	for (int i = n - 1; i >= 0; i--)
		if (sa[i] >= 1 && ls[sa[i] - 1])
			sa[--buf[s[sa[i] - 1] + 1]] = sa[i] - 1;
}

/**
* @brief helper function for the suffix array induced sorting algorithm.
* Determines the order of the LMS substrings in a given string.
* @param s The string for which to resolve the equivalence classes.
* @param sa The array that stores the suffix array.
* @param cnt_l The array that stores the count of L-type characters.
* @param cnt_s The array that stores the count of S-type characters.
* @param ls The array that stores the classification of S-type or L-type.
* @param lms The array that stores the LMS substrings.
* @param lms_map The array that stores the mapping of LMS substrings.
* @note [Complexity]: O(n)
* @note [Attention]: This function is not intended to be used directly.
*/
void sais_resolve(const std::vector<int> &s, std::vector<int> &sa, const std::vector<int> &cnt_l,
		const std::vector<int> &cnt_s, const std::vector<bool> &ls, std::vector<int> &lms, const std::vector<int> &lms_map)
{
	int n = s.size();
	int m = lms.size();
	if (m == 0)
		return;
	std::vector<int> sorted_lms;
	for (int i = 0; i < n; i++)
		if (lms_map[sa[i]] != -1)
			sorted_lms.push_back(sa[i]);
	std::vector<int> rec_s(m);
	int rec_max_s = 0;
	rec_s[lms_map[sorted_lms[0]]] = 0;
	for (int i = 1; i < m; i++)
	{
		int l = sorted_lms[i - 1];
		int r = sorted_lms[i];
		int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
		int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
		if (end_l - l != end_r - r)
			rec_max_s++;
		else
		{
			while (l < end_l && s[l] == s[r])
			{
				l++;
				r++;
			}
			if (l == n || s[l] != s[r])
				rec_max_s++;
		}
		rec_s[lms_map[sorted_lms[i]]] = rec_max_s;
	}
	std::vector<int> rec_sa = sais(rec_s, rec_max_s);
	std::copy(lms.begin(), lms.end(), sorted_lms.begin());
	for (int i = 0; i < m; i++)
		lms[i] = sorted_lms[rec_sa[i]];
	sais_induce(s, sa, cnt_l, cnt_s, ls, lms);
}

/**
* @brief Computes the suffix array of a given string using the induced sorting algorithm.
* @param s The string for which to compute the suffix array.
* @param max_s The maximum value of the characters in the string.
* @return A suffix array for the given string.
* @note [Complexity]: O(n)
*/
std::vector<int> sais(const std::vector<int> &s, const int max_s)
{
	const int threshold_doubling = 100;
	int n = s.size();
	if (n == 0)
		return std::vector<int>();
	if (n == 1)
		return std::vector<int>({0});
	if (n == 2)
	{
		if (s[0] < s[1])
			return std::vector<int>({0, 1});
		else
			return std::vector<int>({1, 0});
	}
	if (n < threshold_doubling)
		return suffixarray_doubling(s);
	std::vector<int> sa(n);
	std::vector<bool> ls(n, false);
	std::vector<int> cnt_l(max_s + 1), cnt_s(max_s + 1);
	std::vector<int> lms_map(n, -1), lms;

	sais_classify_sl(s, ls);
	sais_character_count(s, cnt_l, cnt_s, ls, max_s);
	sais_search_lms(n, ls, lms_map, lms);
	sais_induce(s, sa, cnt_l, cnt_s, ls, lms);
	sais_resolve(s, sa, cnt_l, cnt_s, ls, lms, lms_map);
	return sa;
}

} // namespace helper

/**
* @brief Computes the suffix array of a given string.
* @param s The string for which to compute the suffix array, represented as a vector of integers.
* @param max_s The maximum value of the characters in the string.
* @return A suffix array for the given string.
* @note [Complexity]: O(n)
*/
std::vector<int> suffixarray(const std::vector<int> &s, const int max_s)
{
	return helper::sais(s, max_s);
}


/**
* @brief Computes the suffix array of a given string.
* @param s The string for which to compute the suffix array, represented as a vector of integers.
* @return A suffix array for the given string.
* @note [Complexity]: O(n)
*/
std::vector<int> suffixarray(const std::vector<int> &s)
{
	int max_s = *std::max_element(s.begin(), s.end());
	return helper::sais(s, max_s);
}

/**
* @brief Computes the suffix array of a given string.
* @param str The string for which to compute the suffix array.
* @return A suffix array for the given string.
* @note [Complexity]: O(n)
*/
std::vector<int> suffixarray(const std::string &str)
{
	int n = str.size();
	std::vector<int> s(n);
	for (int i = 0; i < n; i++)
		s[i] = str[i];
	return helper::sais(s, 255);
}

} // namespace string

} // namespace toolbox


namespace toolbox
{

namespace string
{

struct fm_index
{
	fm_index() = default;
	fm_index(const fm_index &) = default;
	fm_index(fm_index &&) = default;
	fm_index &operator=(const fm_index &) = default;
	fm_index &operator=(fm_index &&) = default;
	~fm_index() = default;
	fm_index(const std::string &s) {build(s);}
	fm_index(const std::string &s, const std::string &order) {build(s, order);}

	/**
	* @brief Counts the number of occurrences of a pattern in the indexed string.
	* @param p The pattern to search for.
	* @return The number of occurrences of the pattern in the indexed string.
	* @note [complexity]: O(m), where m is the length of the pattern.
	*/
	int count(const std::string &p)
	{
		int m = p.size();
		int l = 0, r = _n - 1;
		for (int i = m - 1; i >= 0; i--)
		{
			if (_order[(int)p[i]] == -1)
				return 0;
			if (l - 1 == -1)
				l = _c[_order[(int)p[i]]];
			else
				l = _c[_order[(int)p[i]]] + _occ[_order[(int)p[i]]][l - 1];
			r = _c[_order[(int)p[i]]] + _occ[_order[(int)p[i]]][r] - 1;
		}
		return r - l + 1;
	}

	/**
	* @brief Locates the occurrences of a pattern in the indexed string.
	* @param p The pattern to search for.
	* @return A vector containing the starting positions of the occurrences of the pattern in the indexed string.
	* @note [complexity]: O(m), where m is the length of the pattern.
	*/
	std::vector<int> locate(const std::string &p)
	{
		int m = p.size();
		int l = 0, r = _n - 1;
		for (int i = m - 1; i >= 0; i--)
		{
			if (_order[(int)p[i]] == -1)
				return std::vector<int>();
			if (l - 1 == -1)
				l = _c[_order[(int)p[i]]];
			else
				l = _c[_order[(int)p[i]]] + _occ[_order[(int)p[i]]][l - 1];
			r = _c[_order[(int)p[i]]] + _occ[_order[(int)p[i]]][r] - 1;
		}
		std::vector<int> res;
		for (int i = l; i <= r; i++)
			res.push_back(_sa[i]);
		return res;
	}

private:
	int _n;
	int _num_c;
	std::vector<int> _order;
	std::string _s;
	std::vector<int> _sa;
	std::string _bwt;
	std::vector<std::vector<int>> _occ;
	std::vector<int> _c;

	void build(const std::string &s)
	{
		_n = s.size();
		_s = s;
		std::vector<int> cnt(256, 0);
		for (int i = 0; i < _n; i++)
			cnt[(int)_s[i]]++;
		assert(cnt[(int)'$'] == 0 || (cnt[(int)'$'] == 1 && _s[_n - 1] == '$'));
		if (cnt[(int)'$'] == 0)
		{
			_s += '$';
			_n++;
		}
		_order.assign(256, -1);
		_order['$'] = 0;
		int rank = 0;
		for (int i = 1; i < 256; i++)
			if (cnt[i] > 0 && (char)i != '$')
				_order[i] = ++rank;
		_num_c = rank;
		build_sa_bwt();
		build_occ();
		build_c();
	}

	void build(const std::string &s, const std::string &order)
	{
		_n = s.size();
		_s = s;
		assert(find(_s.begin(), _s.end() - 1, '$') == _s.end() - 1);
		if (_s.back() != '$')
		{
			_s += '$';
			_n++;
		}
		_order.assign(256, -1);
		_order[(int)'$'] = 0;
		int rank = 0;
		for (int i = 0; i < 256; i++)
		{
			if (_order[(int)order[i]] != -1)
				continue;
			_order[(int)order[i]] = ++rank;
		}
		_num_c = rank;
		build_sa_bwt();
		build_occ();
		build_c();
	}

	void build_sa_bwt()
	{
		std::vector<int> s_int(_n);
		for (int i = 0; i < _n; i++)
			s_int[i] = _order[(int)_s[i]];
		_sa = toolbox::string::suffixarray(s_int, _num_c);
		_bwt.resize(_n);
		for (int i = 0; i < _n; i++)
			_bwt[i] = _s[(_sa[i] + _n - 1) % _n];
	}

	void build_occ()
	{
		_occ.assign(_num_c + 1, std::vector<int>(_n, 0));
		_occ[_order[(int)_bwt[0]]][0]++;
		for (int i = 1; i < _n; i++)
		{
			for (int j = 0; j <= _num_c; j++)
				_occ[j][i] = _occ[j][i - 1];
			_occ[_order[(int)_bwt[i]]][i]++;
		}
	}

	void build_c()
	{
		_c.assign(_num_c + 1, 0);
		for (int i = 0; i < _n; i++)
			_c[_order[(int)_bwt[i]]]++;
		for (int i = 1; i <= _num_c; i++)
			_c[i] += _c[i - 1];
		for (int i = _num_c; i > 0; i--)
			_c[i] = _c[i - 1];
		_c[0] = 0;
	}
};

} // namespace string

} // namespace toolbox


int main()
{
	string S;
	cin >> S;
	toolbox::string::fm_index idx(S);
	ll Q;
	cin >> Q;
	for (ll i = 0; i < Q; i++)
	{
		string T;
		cin >> T;
		cout << idx.count(T) << endl;
	}
}
