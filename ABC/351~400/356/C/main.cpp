#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, M, K;
	cin >> N >> M >> K;
	vector<ll> C(M);
	vector<vector<ll>> A(M, vector<ll>());
	vector<bool> open(M);
	string R;
	for (int i = 0; i < M; i++)
	{
		cin >> C[i];
		A[i].resize(C[i]);
		for (int j = 0; j < C[i]; j++)
		{
			cin >> A[i][j];
		}
		cin >> R;
		if (R == "o")
			open[i] = true;
		else
			open[i] = false;
	}

	int ans = 0;
	for (int x = 0; x < (1 << N); x++)
	{
		bool ok = true;
		for (int i = 0; i < M; i++)
		{
			int cnt = 0;
			for (int j = 0; j < C[i]; j++)
			{
				if ((x >> (A[i][j] - 1)) & 1)
					cnt++;
			}
			ok &= (cnt >= K) == open[i];
		}
		if (ok)
			ans++;
	}
	cout << ans << endl;
}
