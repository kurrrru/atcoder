#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	string s, t;
	while (N--)
	{
		cin >> t;
		if (s == t && s == "sweet" && N > 0)
		{
			cout << "No" << endl;
			return 0;
		}
		s = t;
	}
	cout << "Yes" << endl;
}
