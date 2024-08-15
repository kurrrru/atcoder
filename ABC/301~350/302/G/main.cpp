#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> A[i];
		A[i]--;
	}
	vector<ll> box(4, 0);
	for (ll i = 0; i < N; i++)
	{
		box[A[i]]++;
	}
	for (ll i = 1; i < 4; i++)
	{
		box[i] += box[i - 1];
	}
	vector<vector<ll>> cnt(4, vector<ll>(4, 0));
	ll box_num = 0;
	for (ll i = 0; i < N; i++)
	{
		while (i == box[box_num])
		{
			box_num++;
		}
		if (box_num != A[i])
		{
			cnt[box_num][A[i]]++;
		}
	}
	ll ans = 0;
	for (ll k = 2; k <= 4; k++)
	{
		// for (ll i = 0; i < 4; i++)
		// {
		// 	for (ll j = 0; j < 4; j++)
		// 	{
		// 		cout << cnt[i][j] << " \n"[j == 3];
		// 	}
		// }
		// cout << endl;
		vector<ll> perm(4, 0);
		iota(perm.begin(), perm.end(), 0);
		do
		{
			ll tmp = cnt[perm[0]][perm[1]];
			for (ll i = 1; i < k; i++)
			{
				tmp = min(tmp, cnt[perm[i]][perm[(i + 1) % k]]);
			}
			for (ll i = 0; i < k; i++)
			{
				cnt[perm[i]][perm[(i + 1) % k]] -= tmp;
			}
			ans += tmp * (k - 1);
		} while (next_permutation(perm.begin(), perm.end()));
	}
	cout << ans << endl;
}
