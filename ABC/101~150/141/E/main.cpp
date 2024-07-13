#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace toolbox
{

/**
* @brief Computes the Z-array, which satisfies Z[i] = the length of lcp(S, S[i:]).
* @param S The string for which to compute the Z-algorithm.
* @return A Z-array for the given string.
* @note [Complexity]: O(|S|)
*/
std::vector<int> zalgorithm(const std::string &S)
{
	int n = S.size();
	std::vector<int> ans(n, 0);
	ans[0] = n;
	int start = 1, length = 0;
	while (start < n)
	{
		while (start + length < n && S[length] == S[start + length])
			++length;
		ans[start] = length;
		if (length == 0)
		{
			++start;
			continue;
		}
		int inner = 1;
		while (start + inner < n && inner + ans[inner] < length)
		{
			ans[start + inner] = ans[inner];
			++inner;
		}
		start += inner;
		length -= inner;
	}
	return ans;
}

} // namespace toolbox

int main()
{
	ll N;
	cin >> N;
	string S;
	cin >> S;
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		string T = S.substr(i);
		auto Z = toolbox::zalgorithm(T);
		for (ll j = 0; j < T.size(); j++)
			ans = max(ans, min(j, (ll)Z[j]));
	}
	cout << ans << endl;
}
