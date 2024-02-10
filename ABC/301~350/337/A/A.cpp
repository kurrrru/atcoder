#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b, T = 0, A = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		T += a;
		A += b;
	}
	if (T > A)
		cout << "Takahashi" << endl;
	else if (T < A)
		cout << "Aoki" << endl;
	else
		cout << "Draw" << endl;
}