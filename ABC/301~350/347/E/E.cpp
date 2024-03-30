#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, Q;
	cin >> N >> Q;
	vector<long long> x(Q);
	for(long long i = 0; i < Q; i++)
	{
		cin >> x[i];
	}
	long long inset[N + 1] = {};
	long long cnt = 0;
	long long ans[N] = {};
	long long acc[Q + 1] = {};
	vector<long long> memo[N+1];
	for(long long i = 0; i < Q; i++)
	{
		if(inset[x[i]] == 0)
		{
			inset[x[i]] = 1;
			cnt++;
		}
		else
		{
			inset[x[i]] = 0;
			cnt--;
		}
		memo[x[i]].push_back(i);
		acc[i + 1] = acc[i] + cnt;
	}
	for (long long i = 0; i <= N; i++)
	{
		if (inset[i] == 1)
		{
			memo[i].push_back(Q);
		}
	}
	// // output memo
	// for (long long i = 0; i <= N; i++)
	// {
	// 	cout << i << ": ";
	// 	for (long long j = 0; j < memo[i].size(); j++)
	// 	{
	// 		cout << memo[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// // output acc
	// for (long long i = 0; i <= Q; i++)
	// {
	// 	cout << acc[i] << " ";
	// }
	// cout << endl;



	for (long long i = 0; i < N; i++)
	{
		if (memo[i + 1].size() == 0)
		{
			cout << 0 << " ";
			continue;
		}
		for (long long j = 0; j < memo[i + 1].size() - 1; j += 2)
		{
			// cout << "i: " << i << " j: " << j << " " << endl;
			ans[i] += acc[memo[i + 1][j + 1]] - acc[memo[i + 1][j]];
		}
		cout << ans[i] << " ";
	}
	cout << endl;

}