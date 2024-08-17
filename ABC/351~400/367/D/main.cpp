#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static unsigned int popcount(unsigned int x)
{
	x = (x & 0b01010101010101010101010101010101) + ((x >> 1) & 0b01010101010101010101010101010101);
	x = (x & 0b00110011001100110011001100110011) + ((x >> 2) & 0b00110011001100110011001100110011);
	x = (x & 0b00001111000011110000111100001111) + ((x >> 4) & 0b00001111000011110000111100001111);
	x = (x & 0b00000000111111110000000011111111) + ((x >> 8) & 0b00000000111111110000000011111111);
	x = (x & 0b00000000000000001111111111111111) + ((x >> 16) & 0b00000000000000001111111111111111);
	return (x);
}

static int bit_width(int x)
{
	int ret = 0;
	while (x)
	{
		x >>= 1;
		ret++;
	}
	return (ret);
}

struct bitvector {
	bitvector() = default;
	bitvector(std::vector<bool> &arr) { build(arr); }

	// build
	// @ arr: input array
	// return: void
	void build(std::vector<bool> &arr)
	{
		_len = arr.size();
		_num_blocks = (_len + 0b11111) >> 5;
		_bit.assign(_num_blocks, 0u);
		_sum.assign(_num_blocks + 1, 0u);
		_set(arr);
		for (std::size_t i = 1; i <= _num_blocks; i++)
			_sum[i] = _sum[i - 1] + popcount(_bit[i - 1]);
	}

	// operator[]
	// @ i: index
	// return: value of the bit at index i
	bool operator[](int i)
	{
		assert(i < _len);
		return (_bit[i >> 5] & (1u << (i & 0b11111)));
	}

	// rank
	// @ i: index
	// Count the occurrence of 1 in [0, i) in O(1) time
	// O(n) bits are used in this implementation, but it can be reduced to n + o(n) bits
	// return: the occurrence of 1 in [0, i)
	int rank(int i)
	{
		assert(i <= _len);
		if (i == 0)
			return (0);
		return (_sum[i >> 5] + popcount(_bit[i >> 5] & ((1u << (i & 0b11111)) - 1)));
	}

	// select
	// @ j: the j-th occurrence of 1
	// Ideally, time complexity is O(1), but it is O(log n) in this implementation 
	// return: the index of the j-th occurrence of 1
	int select(int j)
	{
		assert(0 < j && j <= _sum[_num_blocks]);
		int left = -1, right = _len;
		while (left + 1 < right)
		{
			int mid = (left + right) >> 1;
			if (rank(mid) < j)
				left = mid;
			else
				right = mid;
		}
		return (left);
	}

private:
	std::vector<unsigned int> _bit;
	std::vector<unsigned int> _sum;
	int _num_blocks;
	int _len;

	void	_set(std::vector<bool> &arr)
	{
		for (int i = 0; i < _len; i++)
			if (arr[i])
				_bit[i >> 5] |= 1u << (i & 0b11111);
	}
};

struct wavelet_tree
{
	wavelet_tree() = default;
	wavelet_tree(std::vector<int> &arr)
	{
		build(arr);
	}

	// wavelet_tree::build
	// @ arr: input array
	// assumption: min(arr) = 0
	// Build a wavelet tree in O(n log s) time (s = _size, n = _len)
	// return: void
	void build(std::vector<int> &arr)
	{
		_len = arr.size();
		if (_len == 0)
			_size = 0;
		else
			_size = *std::max_element(arr.begin(), arr.end()) + 1;
		_capacity = 1 << bit_width(_size);
		_build_rec(&root, arr, 0, _capacity);
	}

	// wavelet_tree::access
	// @ i: index
	// Access the i-th element in O(log s) time (s = _size)
	// return: value of the bit at index i
	int access(int i)
	{
		assert(i < _len);
		_node *cur = root;
		int ret = 0;
		while (cur != nullptr && cur->_l < cur->_r - 1)
		{
			if (cur->_bv[i])
			{
				ret += (cur->_r - cur->_l) / 2;
				i = cur->_bv.rank(i);
				cur = cur->right;
			}
			else
			{
				i = i - cur->_bv.rank(i);
				cur = cur->left;
			}
		}
		return (ret);
	}

	// wavelet_tree::rank
	// @ i: index
	// @ c: character
	// Count the occurrence of c in [0, i) in O(log s) time (s = _size)
	// return: the occurrence of c in [0, i)
	int rank(int i, int c)
	{
		assert(i <= _len);
		if (i == 0 || c >= _size)
			return (0);
		_node *cur = root;
		while (cur->_l < cur->_r - 1)
		{
			int mid = (cur->_r + cur->_l) >> 1;
			if (c >= mid)
			{
				i = cur->_bv.rank(i);
				cur = cur->right;
			}
			else
			{
				i = i - cur->_bv.rank(i);
				cur = cur->left;
			}
			if (cur == nullptr)
				return (0);
		}
		return (i);
	}

	// wavelet_tree::range_count
	// @ i: index (inclusive)
	// @ j: index (exclusive)
	// @ lower: lower bound of the range of characters (inclusive)
	// @ upper: upper bound of the range of characters (exclusive)
	// Count the number of k that satisfies i <= k < j and lower <= T[k] < upper
	// return: the number of k that satisfies the condition
	int range_count(int i, int j, int lower, int upper)
	{
		assert(lower <= upper);
		return (_range_count_rec(root, i, j, lower, upper));
	}

	// wavelet_tree::freq
	// @ i: index (inclusive)
	// @ j: index (exclusive)
	// @ c: character
	// Count the number of k that satisfies i <= k < j and T[k] = c
	// return: the number of k that satisfies the condition
	int freq(int i, int j, int c)
	{
		return (rank(j, c) - rank(i, c));
	}

	// wavelet_tree::is_range_unary
	// @ i: index (inclusive)
	// @ j: index (exclusive)
	// Check if the range [i, j) is unary
	// return: true if the range is unary, false otherwise
	bool is_range_unary(int i, int j)
	{
		assert(i < _len);
		return (freq(i, j, access(i)) == j - i);
	}

	// wavelet_tree::range_list
	// @ i: index (inclusive)
	// @ j: index (exclusive)
	// @ lower: lower bound of the range of characters (inclusive)
	// @ upper: upper bound of the range of characters (exclusive)
	// list the characters in [i, j) that satisfies lower <= T[k] < upper
	// return: the list of characters
	std::vector<int> range_list(int i, int j, int lower, int upper)
	{
		std::vector<int> v;
		_range_list_rec(root, i, j, lower, upper, v);
		return (v);
	}

private:
	struct _node
	{
		int _l, _r;
		bitvector _bv;
		_node *left, *right;
		_node(int l, int r, std::vector<bool> &arr)
			: _l(l), _r(r), _bv(arr), left(nullptr), right(nullptr) {}
	};
	_node *root;
	int _len;
	int _size;
	int _capacity;

	void _build_rec(_node **cur, std::vector<int> &arr, int lower, int upper)
	{
		std::vector<bool> bit(arr.size());
		std::vector<int> left_arr, right_arr;
		if (lower >= _size || upper == lower)
			return ;
		int mid = (lower + upper) >> 1;
		for (int i = 0; i < (int)arr.size(); i++)
		{
			bit[i] = (arr[i] >= mid);
			if (bit[i])
				right_arr.push_back(arr[i]);
			else
				left_arr.push_back(arr[i]);
		}
		*cur = new _node(lower, upper, bit);
		if (lower == upper - 1)
			return ;
		_build_rec(&((*cur)->left), left_arr, lower, mid);
		_build_rec(&((*cur)->right), right_arr, mid, upper);
	}

	int _range_count_rec(_node *cur, int i, int j, int lower, int upper)
	{
		if (cur == nullptr || i >= j || upper <= cur->_l || lower >= cur->_r)
			return (0);
		if (lower <= cur->_l && cur->_r <= upper)
			return (j - i);
		return (_range_count_rec(cur->right, cur->_bv.rank(i), cur->_bv.rank(j), lower, upper) +
				_range_count_rec(cur->left, i - cur->_bv.rank(i), j - cur->_bv.rank(j), lower, upper));
	}

	void _range_list_rec(_node *cur, int i, int j, int lower, int upper, std::vector<int> &v)
	{
		if (cur == nullptr || i >= j || upper <= cur->_l || lower >= cur->_r)
			return ;
		if (lower <= cur->_l && cur->_r <= upper && cur->_l == cur->_r - 1)
		{
			v.push_back(cur->_l);
			return ;
		}
		_range_list_rec(cur->left, i - cur->_bv.rank(i), j - cur->_bv.rank(j), lower, upper, v);
		_range_list_rec(cur->right, cur->_bv.rank(i), cur->_bv.rank(j), lower, upper, v);
	}
};

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N);
	for (ll i = 0; i < N; ++i)
		cin >> A[i];
	vector<ll> acc(N + 1, 0);
	for (ll i = 0; i < N; ++i)
	{
		acc[i + 1] = acc[i] + A[i];
	}
	ll sum = acc[N];
	vector<int> acc_mod(N + 1, 0);
	for (ll i = 0; i <= N; ++i)
	{
		acc_mod[i] = acc[i] % M;
	}
	wavelet_tree wt;
	wt.build(acc_mod);
	ll ans = 0;
	for (ll i = 0; i < N; ++i)
	{
		ans += wt.range_count(i + 1, N, acc_mod[i], acc_mod[i] + 1);
		ans += wt.range_count(0, i, (acc_mod[i] - sum % M + M) % M, (acc_mod[i] - sum % M + M) % M + 1);
	}
	cout << ans << endl;
}
