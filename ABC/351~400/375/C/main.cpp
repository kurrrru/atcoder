#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<string> S(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	vector<string> ans(N, string(N, '?'));
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			ll t = min({i, j, N - i - 1, N - j - 1});
			switch (t % 4)
			{
			case 3:
				ans[i][j] = S[i][j];
				break;
			case 0:
				ans[i][j] = S[N - j - 1][i];
				break;
			case 1:
				ans[i][j] = S[N - i - 1][N - j - 1];
				break;
			case 2:
				ans[i][j] = S[j][N - i - 1];
				break;
			default:
				break;
			}
			cout << ans[i][j];
		}
		cout << endl;
	}
}
