#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dp;
vector<ll> A, B;
ll N;

ll grundy(ll S) //残りのペア数
{
	// cout << bitset<18>(S) << endl;
	if (dp[S] != -1)
		return dp[S];
	ll next_S;
	ll next_num_pair = 0;
	bool pair_flag = false;
	for (ll i = 0; i < N - 1; i++)
	{
		if ((S & (1 << i)) == 0)
			continue;
		for (ll j = i + 1; j < N; j++)
		{
			if ((S & (1 << j)) == 0)
				continue;
			if (A[i] == A[j])
			{
				// cout << "A[i] == A[j]" << " i: " << i << " j: " << j << endl;
				next_S = S;
				next_S &= ~(1 << i);
				next_S &= ~(1 << j);
				pair_flag = true;
				next_num_pair |= (1 << grundy(next_S));
			}
			if (B[i] == B[j])
			{
				// cout << "B[i] == B[j]" << " i: " << i << " j: " << j << endl;
				next_S = S;
				next_S &= ~(1 << i);
				next_S &= ~(1 << j);
				pair_flag = true;
				next_num_pair |= (1 << grundy(next_S));
			}
		}
	}
	if (!pair_flag)
	{
		dp[S] = 0;
		return (0);
	}
	for (ll i = 0; i <= N; i++)
	{
		if ((next_num_pair & (1 << i)) == 0)
		{
			dp[S] = i;
			break;
		}
	}
	return (dp[S]);
}

int main()
{
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i] >> B[i];
	dp.assign(1 << N, -1);
	ll g = grundy((1 << N) - 1);
	if (g == 0)
		cout << "Aoki" << endl;
	else
		cout << "Takahashi" << endl;
}