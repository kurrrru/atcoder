#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, T, A;
	cin >> N >> T >> A;
	if (T * 2 > N || A * 2 > N)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
