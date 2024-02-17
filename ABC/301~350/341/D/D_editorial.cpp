#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M, K;
	cin >> N >> M >> K;
	ll L = lcm(N, M);
	ll l = 0, r = 1e18, mid;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (mid / N + mid / M - mid / L * 2 >= K)
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}
