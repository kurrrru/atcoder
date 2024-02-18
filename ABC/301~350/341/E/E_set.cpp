#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	set<int> I;
	for (int i = 0; i < N - 1; i++)
		if (s[i] == s[i + 1])
			I.insert(i);
	for (int i = 0; i < Q; i++)
	{
		int x, l, r;
		cin >> x >> l >> r;
		l--; r--;
		if (x == 1)
		{
			if (I.find(l - 1) == I.end())
				I.insert(l - 1);
			else
				I.erase(l - 1);
			if (I.find(r) == I.end())
				I.insert(r);
			else
				I.erase(r);
		}
		else
		{
			auto it = I.lower_bound(l);
			if (it == I.end() || *it >= r)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}