#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, L, R;
	cin >> N >> L >> R;
	for (int i = 1; i < L; i++)
	{
		cout << i << " ";
	}
	for (int i = R; i >= L; i--)
	{
		cout << i << " ";
	}
	for (int i = R + 1; i <= N; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
