#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M, K;
	cin >> N >> M >> K;
	if (K < N || (N - K) % 2 != 0)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	vector<vector<char>> ans(2 * N + 1, vector<char>(2 * M + 1, '+'));
	ans[0][2 * M - 1] = 'S';
	ans[2 * N][2 * M - 1] = 'G';
	for (ll i = 1; i < 2 * N; i++)
	{
		for (ll j = 1; j < 2 * M; j++)
		{
			ans[i][j] = '.';
		}
	}
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < M; j++)
		{
			ans[2 * i + 1][2 * j + 1] = 'o';
			ans[2 * i][2 * j] = '+';
		}
	}



	for (ll i = 0; i < N; i++)
	{
		if (K == N - i)
		{
			if (M != 1)
			{
				ans[2 * i + 1][2 * M - 2] = '|';
			}
			K--;
		}
		else if (N % 2 == 0 || i < N - 3)
		{
			ll diff = min(M - 1, (K - (N - i)) / 2);
			for (ll j = M - diff; j < M; j++)
			{
				ans[2 * i + 2][2 * j + 1] = '-';
				if (2 * i + 4 <= 2 * N - 2  && ans[2 * i + 4][2 * j - 1] != '+')
					ans[2 * i + 4][2 * j - 1] = '-';
			}
			if (2 * i + 3 <= 2 * N && diff < M - 1)
			{
				ans[2 * i + 1][(M - diff - 1) * 2] = '|';
				ans[2 * i + 3][(M - diff - 1) * 2] = '|';
			}
			K -= diff * 2 + 2;
			i++;
		}
		else
		{
			ll diff = min(M - 1, (K - (N - i)) / 2);
			if (diff < M - 1)
			{
				for (ll j = M - diff; j < M; j++)
				{
					ans[2 * i + 2][2 * j + 1] = '-';
					if (2 * i + 4 <= 2 * N - 2  && ans[2 * i + 4][2 * j - 1] != '+')
						ans[2 * i + 4][2 * j - 1] = '-';
				}
				if (2 * i + 3 <= 2 * N && diff < M - 1)
				{
					ans[2 * i + 1][(M - diff - 1) * 2] = '|';
					ans[2 * i + 3][(M - diff - 1) * 2] = '|';
				}
				K -= diff * 2 + 2;
				i++;
			}
			else
			{
				for (ll j = M - diff; j < M; j++)
				{
					ans[2 * i + 2][2 * j + 1] = '-';
				}
				K -= M;
				diff = (K - M - 1) / 2;
				for (ll j = 0; j < diff; j ++)
				{
					ans[2 * N - 3][4 * j + 2] = '|';
					ans[2 * N - 1][4 * j + 4] = '|';
				}
				for (ll j = 2 * diff; j < M - 1; j++)
				{
					ans[2 * N - 2][2 * j + 1] = '-';
				}
				ans[2 * N - 1][2 * M - 2] = '|';
				K -= diff * 2 + 1 + M;
				i += 2;
			}
		}
	}

	// display
	for (ll i = 0; i < 2 * N + 1; i++)
	{
		for (ll j = 0; j < 2 * M + 1; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}

}
