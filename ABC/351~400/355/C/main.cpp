#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, T;
	cin >> N >> T;
	vector<ll> col(N, N);
	vector<ll> line(N, N);
	vector<ll> diag(2, N);
	ll num;
	for (ll i = 0; i < T; i++)
	{
		cin >> num;
		col[(num - 1) % N]--;
		line[(num - 1) / N]--;
		if ((num - 1) % N == (num - 1) / N)
			diag[0]--;
		if ((num - 1) % N == N - 1 - (num - 1) / N)
			diag[1]--;
		if (col[(num - 1) % N] == 0 || line[(num - 1) / N] == 0 || diag[0] == 0 || diag[1] == 0)
		{
			cout << i + 1 << endl;
			return (0);
		}
	}
	cout << -1 << endl;
	return (0);
}
