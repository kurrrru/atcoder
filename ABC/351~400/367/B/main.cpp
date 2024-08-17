#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string X;
	cin >> X;
	int N = X.size();
	while (X[N - 1] == '0' || X[N - 1] == '.')
	{
		if (X[N - 1] == '.')
		{
			N--;
			break;
		}
		N--;
	}
	for (int i = 0; i < N; i++)
	{
		cout << X[i];
	}
	cout << endl;
}
