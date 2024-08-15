#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll H, ll W, vector<vector<ll>> A)
{
	vector<bool> isolate(W, false);
	isolate[0] = A[0][0] != A[0][1];
	isolate[W - 1] = A[0][W - 1] != A[0][W - 2];
	for (ll i = 1; i < W - 1; i++)
	{
		isolate[i] = A[0][i] != A[0][i - 1] && A[0][i] != A[0][i + 1];
	}
	ll ans = 0;
	for (ll i = 1; i < H; i++)
	{
		ll cnt = 0;
		for (ll j = 0; j < W; j++)
		{
			cnt += isolate[j];
		}
		if (cnt != 0)
		{
			ll cnt_front = 0;
			ll cnt_back = 0;
			if (i < H - 1)
			{
				for (ll j = 0; j < W; j++)
				{
					if (!isolate[j])
					{
						continue;
					}
					if (A[i][j] != A[i - 1][j])
					{
						cnt_front++;
					}
					else
					{
						cnt_back++;
					}
				}
			}
			else
			{
				vector<bool> isolate2(W, false);
				isolate2[0] = A[i][0] != A[i][1];
				isolate2[W - 1] = A[i][W - 1] != A[i][W - 2];
				for (ll j = 1; j < W - 1; j++)
				{
					isolate2[j] = A[i][j] != A[i][j - 1] && A[i][j] != A[i][j + 1];
				}
				for (ll j = 0; j < W; j++)
				{
					if ((isolate[j] || isolate2[j]) && A[i][j] != A[i - 1][j])
					{
						cnt_front++;
					}
					else if ((isolate[j] || isolate2[j]) && A[i][j] == A[i - 1][j])
					{
						cnt_back++;
					}
				}
			}
			if (cnt_front > 0 && cnt_back > 0)
			{
				cout << -1 << endl;
				return -1;
			}
			if (cnt_back == 0)
			{
				ans++;
				for (ll j = 0; j < W; j++)
				{
					A[i][j] = 1 - A[i][j];
				}
			}
		}
		else
		{
			vector<bool> isolate2(W, false);
			isolate2[0] = A[i][0] != A[i][1];
			isolate2[W - 1] = A[i][W - 1] != A[i][W - 2];
			for (ll j = 1; j < W - 1; j++)
			{
				isolate2[j] = A[i][j] != A[i][j - 1] && A[i][j] != A[i][j + 1];
			}
			ll cnt2 = 0;
			for (ll j = 0; j < W; j++)
			{
				cnt2 += isolate2[j];
			}
			if (cnt2 != 0)
			{
				if (i == H - 1)
				{
					ll cnt_front = 0;
					ll cnt_back = 0;
					for (ll j = 0; j < W; j++)
					{
						if (!isolate2[j])
						{
							continue;
						}
						if (A[i][j] != A[i - 1][j])
						{
							cnt_front++;
						}
						else
						{
							cnt_back++;
						}
					}
					if (cnt_front > 0 && cnt_back > 0)
					{
						cout << -1 << endl;
						return -1;
					}
					if (cnt_front > 0)
					{
						ans++;
						for (ll j = 0; j < W; j++)
						{
							A[i][j] = 1 - A[i][j];
						}
					}
				}
				else
				{
					ll cnt_front = 0;
					ll cnt_back = 0;
					for (ll j = 0; j < W; j++)
					{
						if (!isolate2[j])
						{
							continue;
						}
						if (A[i][j] != A[i + 1][j])
						{
							cnt_front++;
						}
						else
						{
							cnt_back++;
						}
					}
					if (cnt_front > 0 && cnt_back > 0)
					{
						ll cnt_front2 = 0;
						ll cnt_back2 = 0;
						for (ll j = 0; j < W; j++)
						{
							if (!isolate2[j])
							{
								continue;
							}
							if (A[i][j] != A[i - 1][j])
							{
								cnt_front2++;
							}
							else
							{
								cnt_back2++;
							}
						}
						if (cnt_front2 > 0 && cnt_back2 > 0)
						{
							cout << -1 << endl;
							return -1;
						}
						if (cnt_front2 > 0)
						{
							ans++;
							for (ll j = 0; j < W; j++)
							{
								A[i][j] = 1 - A[i][j];
							}
						}
					}
				}
			}
		}
		isolate[0] = A[i][0] != A[i][1] && A[i][0] != A[i - 1][0];
		isolate[W - 1] = A[i][W - 1] != A[i][W - 2] && A[i][W - 1] != A[i - 1][W - 1];
		for (ll j = 1; j < W - 1; j++)
		{
			isolate[j] = A[i][j] != A[i][j - 1] && A[i][j] != A[i][j + 1] && A[i][j] != A[i - 1][j];
		}
	}
	for (ll i = 0; i < W; i++)
	{
		if (isolate[i])
		{
			cout << -1 << endl;
			return -1;
		}
	}
	return ans;
}

int main()
{
	ll H, W;
	cin >> H >> W;
	vector<vector<ll>> A(H, vector<ll>(W));
	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{
			cin >> A[i][j];
		}
	}
	ll ans = func(H, W, A);
	if (ans == -1)
	{
		return 0;
	}
	for (ll i = 0; i < W; i++)
	{
		A[0][i] = 1 - A[0][i];
	}
	ll ans2 = func(H, W, A) + 1;
	cout << min(ans, ans2) << endl;
}
