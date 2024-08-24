#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<ll> H(N);
	for (ll i = 0; i < N; i++)
		cin >> H[i];
	ll cnt = 0;
	for (ll i = 0; i < N; i++)
	{
		if (cnt % 3 == 1 && H[i] > 0)
		{
			cnt++;
			H[i]--;
		}
		if (cnt % 3 == 2 && H[i] > 0)
		{
			cnt++;
			H[i]-= 3;
		}
		cnt += (H[i] / 5) * 3;
		H[i] %= 5;
		if (H[i] == 0)
			continue;
		else if (H[i] == 1)
			cnt++;
		else if (H[i] == 2)
			cnt += 2;
		else if (H[i] == 3 || H[i] == 4)
			cnt += 3;
	}
	cout << cnt << endl;
}
