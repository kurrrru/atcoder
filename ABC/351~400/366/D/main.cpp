#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<vector<vector<ll>>> A(N, vector<vector<ll>>(N, vector<ll>(N, 0)));
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			for (ll k = 0; k < N; k++)
			{
				cin >> A[i][j][k];
			}
		}
	}
	vector<vector<vector<ll>>> acc(N + 1, vector<vector<ll>>(N + 1, vector<ll>(N + 1, 0)));
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			for (ll k = 0; k < N; k++)
			{
				acc[i + 1][j + 1][k + 1] = acc[i + 1][j + 1][k] + acc[i + 1][j][k + 1] + acc[i][j + 1][k + 1] - acc[i][j][k + 1] - acc[i][j + 1][k] - acc[i + 1][j][k] + acc[i][j][k] + A[i][j][k];
			}
		}
	}
	ll Q;
	cin >> Q;
	while (Q--)
	{
		ll Lx, Rx, Ly, Ry, Lz, Rz;
		cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
		cout << acc[Rx][Ry][Rz] - acc[Lx - 1][Ry][Rz] - acc[Rx][Ly - 1][Rz] - acc[Rx][Ry][Lz - 1] + acc[Lx - 1][Ly - 1][Rz] + acc[Lx - 1][Ry][Lz - 1] + acc[Rx][Ly - 1][Lz - 1] - acc[Lx - 1][Ly - 1][Lz - 1] << endl;
	}

	// for (ll i = 0; i <= N; i++)
	// {
	// 	for (ll j = 0; j <= N; j++)
	// 	{
	// 		for (ll k = 0; k <= N; k++)
	// 		{
	// 			cout << acc[i][j][k] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// 	cout << endl;
	// }
}
