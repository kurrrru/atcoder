#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M, K;
	cin >> N >> M >> K;

	ll l = lcm(N, M);
	ll c = l / N + l / M - 2;
	ll ans = 0, cnt;
	ans = (K - 1) / c * l;
	cnt = (K - 1) % c + 1;
	vector<ll> v;
	if (cnt > 1000000)
	{
		int a = cnt * 999 / 1000;
		int b = a * N / (M + N);
		a = a * M / (M + N);
		cnt = cnt - a - b;

		for (int i = 1; i <= cnt; i++)
		{
			if ((ans + N * (a + i)) % M != 0)
				v.push_back(ans + N * (a + i));
			if ((ans + M * (b + i)) % N != 0)
				v.push_back(ans + M * (b + i));
		}
		sort(v.begin(), v.end());
		cout << v.at(cnt - 1) << endl;
	}
	else
	{
		for (int i = 1; i <= cnt; i++)
		{
			if ((ans + N * i) % M != 0)
				v.push_back(ans + N * i);
			if ((ans + M * i) % N != 0)
				v.push_back(ans + M * i);
		}
		sort(v.begin(), v.end());
		cout << v.at(cnt - 1) << endl;
	}


}
