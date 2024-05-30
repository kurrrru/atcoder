#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	long long ans = 0;
	long long n = s.size();
	ans = n * (n - 1) / 2;
	long long cnt[128];
	memset(cnt, 0, sizeof(cnt));
	bool flag = false;

	for (int i = 0; i < n; i++)
	{
		cnt[s[i]]++;
	}
	for (int i = 0; i < 128; i++)
	{
		ans -= cnt[i] * (cnt[i] - 1) / 2;
		if (cnt[i] >= 2)
			flag = true;
	}
	if (flag)
		ans += 1;
	cout << ans << endl;
}