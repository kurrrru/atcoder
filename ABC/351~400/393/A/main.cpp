#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int i = 0;
	string s;
	cin >> s;
	i |= (s == "fine") << 1;
	cin >> s;
	i |= (s == "fine");
	cout << i + 1 << endl;
}
