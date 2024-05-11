#include <bits/stdc++.h>
using namespace std;

long long log10(long long n)
{
	long long c = 0;
	while (n > 0LL)
	{
		n /= 10LL;
		c++;
	}
	return c;
}
long long MOD = 998244353;

long long pow_10[12] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000LL, 1000000000LL, 10000000000LL, 100000000000LL};

int main()
{
	long long N;
	cin >> N;
	vector<long long> A(N);
	vector<long long> B(N);
	for (int i = 0; i < 12; i++)
	{
		pow_10[i] %= MOD;
	}
	for (long long i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i] = log10(A[i]);
	}
	vector<vector<long long> > C(N, vector<long long>(12, 0));
	C[N - 1][B[N - 1]] = 1;
	for (long long i = N - 2; i >= 0; i--)
	{
		for (long long j = 0; j < 12; j++)
		{
			C[i][j] = C[i + 1][j];
		}
		C[i][B[i]]++;
	}
	long long ans = 0;
	for (long long i = 0; i < N - 1; i++)
	{
		for (long long j = 0; j < 12; j++)
		{
			ans += ((A[i] % MOD) * pow_10[j] % MOD) * C[i + 1][j];
			ans %= MOD;
		}
	}
	for (long long i = 0; i < N; i++)
	{
		ans += A[i] * i;
		ans %= MOD;
	}
	//display C
	// for (long long i = 0; i < N; i++)
	// {
	// 	for (long long j = 0; j < 10; j++)
	// 	{
	// 		cout << C[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	cout << ans << endl;

}
