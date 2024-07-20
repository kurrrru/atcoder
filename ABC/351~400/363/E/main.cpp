#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll H, W, Y;
	cin >> H >> W >> Y;
	vector<vector<ll>> A(H, vector<ll>(W));
	for (ll i = 0; i < H; ++i)
		for (ll j = 0; j < W; ++j)
			cin >> A[i][j];
	priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
	for (ll i = 0; i < H; i++)
	{
		if (A[i][0] <= Y)
			pq.push({A[i][0], {i, 0}});
		if (A[i][W - 1] <= Y)
			pq.push({A[i][W - 1], {i, W - 1}});
	}
	for (ll j = 1; j < W - 1; j++)
	{
		if (A[0][j] <= Y)
			pq.push({A[0][j], {0, j}});
		if (A[H - 1][j] <= Y)
			pq.push({A[H - 1][j], {H - 1, j}});
	}
	vector<vector<ll>> sink(H, vector<ll>(W, Y + 1));
	while (!pq.empty())
	{
		auto [c, p] = pq.top();
		pq.pop();
		auto [i, j] = p;
		if (sink[i][j] <= c)
			continue;
		sink[i][j] = c;
		if (i > 0 && A[i - 1][j] <= c)
		{
			pq.push({c, {i - 1, j}});
		}
		else if (i > 0 && A[i - 1][j] <= Y)
		{
			pq.push({A[i - 1][j], {i - 1, j}});
		}
		if (i < H - 1 && A[i + 1][j] <= c)
		{
			pq.push({c, {i + 1, j}});
		}
		else if (i < H - 1 && A[i + 1][j] <= Y)
		{
			pq.push({A[i + 1][j], {i + 1, j}});
		}
		if (j > 0 && A[i][j - 1] <= c)
		{
			pq.push({c, {i, j - 1}});
		}
		else if (j > 0 && A[i][j - 1] <= Y)
		{
			pq.push({A[i][j - 1], {i, j - 1}});
		}
		if (j < W - 1 && A[i][j + 1] <= c)
		{
			pq.push({c, {i, j + 1}});
		}
		else if (j < W - 1 && A[i][j + 1] <= Y)
		{
			pq.push({A[i][j + 1], {i, j + 1}});
		}

		// if (i < H - 1 && A[i + 1][j] <= c)
		// 	pq.push({c, {i + 1, j}});
		// if (j > 0 && A[i][j - 1] <= c)
		// 	pq.push({c, {i, j - 1}});
		// if (j < W - 1 && A[i][j + 1] <= c)
		// 	pq.push({c, {i, j + 1}});
	}
	vector<ll> sink_cnt(Y + 2, 0);
	for (ll i = 0; i < H; i++)
		for (ll j = 0; j < W; j++)
			sink_cnt[sink[i][j]]++;
	ll ans = H * W;
	for (ll i = 1; i <= Y; i++)
	{
		ans -= sink_cnt[i];
		cout << ans << endl;
	}
	// // sink display
	// for (ll i = 0; i < H; i++)
	// {
	// 	for (ll j = 0; j < W; j++)
	// 		cout << sink[i][j] << " ";
	// 	cout << endl;
	// }


}
