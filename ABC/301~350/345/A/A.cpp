#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool flag = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0)
			flag &= (s[i] == '<');
		else if (i == s.size() - 1)
			flag &= (s[i] == '>');
		else
			flag &= (s[i] == '=');
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}