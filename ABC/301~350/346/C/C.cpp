#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, K;
	cin >> N >> K;
	long long A[N];
	for (long long i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	long long ans = K * (K + 1LL) / 2LL;
	set<long long> S{};
	for (long long i = 0; i < N; i++)
	{
		if (A[i] <= K && S.find(A[i]) == S.end())
		{
			// cout << i << A[i] << endl;
			S.insert(A[i]);
			ans -= A[i];
		}
	}
	cout << ans << endl;
}