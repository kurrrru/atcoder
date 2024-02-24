#include <bits/stdc++.h>
using namespace std;

int main()
{
	long N;
	cin >> N;
	long C[300000] = {};
	long A;
	long ans = 0;
	for (long i = 0; i < N; i++)
	{
		cin >> A;
		for (long j = 2; j * j <= A; j++)
		{
			while (A > 0 && A%(j*j)==0)
			{
				A /= j * j;
			}
		}
		ans+=C[A]++;
	}
	ans += C[0] * (N - C[0]);
	cout << ans << endl;
}