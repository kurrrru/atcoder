#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll A, B, C;
	cin >> A >> B >> C;
	if (B < C && (A < B || C < A))
		cout << "Yes" << endl;
	else if (C < B && (C < A && A < B))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}
