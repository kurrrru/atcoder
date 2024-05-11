#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	vector<long long> A(N);
	for (long long i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	long long ans = 0;
	sort(A.begin(), A.end());
	long long c = 0;
	for (long long i = 0; i < N; i++)
		c += A.end() - lower_bound(A.begin(), A.end(), 100000000 - A[i]);
	for (long long i = 0; i < N; i++)
		ans += (N - 1) * A[i];
	c -= A.end() - lower_bound(A.begin(), A.end(), 100000000 / 2);
	c /= 2;
	ans -= c * 100000000;
	cout << ans << endl;

	
}