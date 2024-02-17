#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	long long ans = 0;
	for (long long i = 1; i <= N / i; i++)
	{
		ans += N / i;
		if (i < N / i)
			ans += (N / i - N / (i + 1)) * i;
	}
	cout << ans << endl;
}
