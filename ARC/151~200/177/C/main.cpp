#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sub(ll N, vector<string> S, tuple<ll, ll, ll> start, tuple<ll, ll, ll> goal, char s)
{
	ll INF = 1LL << 60;
	vector<vector<vector<ll> > > dist(2, vector<vector<ll> >(N, vector<ll>(N, INF)));
	deque<tuple<ll, ll, ll> > que;
	que.push_back(start);
	dist[0][get<1>(start)][get<2>(start)] = 0;
	ll p, l, c;
	while (!que.empty())
	{
		tie(p, l, c) = que.front();
		que.pop_front();
		if (p == 1)
		{
			if (l > 0 && dist[1][l][c] < dist[0][l - 1][c] && S[l - 1][c] == s)
			{
				dist[0][l - 1][c] = dist[1][l][c];
				que.push_front(make_tuple(0, l - 1, c));
			}
			if (l > 0 && dist[1][l][c] + 1 < dist[1][l - 1][c])
			{
				dist[1][l - 1][c] = dist[1][l][c] + 1;
				que.push_back(make_tuple(1, l - 1, c));
			}
			if (c > 0 && dist[1][l][c] < dist[0][l][c - 1] && S[l][c - 1] == s)
			{
				dist[0][l][c - 1] = dist[1][l][c];
				que.push_front(make_tuple(0, l, c - 1));
			}
			if (c > 0 && dist[1][l][c] + 1 < dist[1][l][c - 1])
			{
				dist[1][l][c - 1] = dist[1][l][c] + 1;
				que.push_back(make_tuple(1, l, c - 1));
			}
			if (l < N - 1 && dist[1][l][c] < dist[0][l + 1][c] && S[l + 1][c] == s)
			{
				dist[0][l + 1][c] = dist[1][l][c];
				que.push_front(make_tuple(0, l + 1, c));
			}
			if (l < N - 1 && dist[1][l][c] + 1 < dist[1][l + 1][c])
			{
				dist[1][l + 1][c] = dist[1][l][c] + 1;
				que.push_back(make_tuple(1, l + 1, c));
			}
			if (c < N - 1 && dist[1][l][c] < dist[0][l][c + 1] && S[l][c + 1] == s)
			{
				dist[0][l][c + 1] = dist[1][l][c];
				que.push_front(make_tuple(0, l, c + 1));
			}
			if (c < N - 1 && dist[1][l][c] + 1 < dist[1][l][c + 1])
			{
				dist[1][l][c + 1] = dist[1][l][c] + 1;
				que.push_back(make_tuple(1, l, c + 1));
			}
		}
		else
		{
			if (l > 0 && S[l][c] == S[l - 1][c] && dist[0][l][c] < dist[0][l - 1][c])
			{
				dist[0][l - 1][c] = dist[0][l][c];
				que.push_front(make_tuple(0, l - 1, c));
			}
			if (l > 0 && dist[0][l][c] + 1 < dist[1][l - 1][c])
			{
				dist[1][l - 1][c] = dist[0][l][c] + 1;
				que.push_back(make_tuple(1, l - 1, c));
			}
			if (c > 0 && S[l][c] == S[l][c - 1] && dist[0][l][c] < dist[0][l][c - 1])
			{
				dist[0][l][c - 1] = dist[0][l][c];
				que.push_front(make_tuple(0, l, c - 1));
			}
			if (c > 0 && dist[0][l][c] + 1 < dist[1][l][c - 1])
			{
				dist[1][l][c - 1] = dist[0][l][c] + 1;
				que.push_back(make_tuple(1, l, c - 1));
			}
			if (l < N - 1 && S[l][c] == S[l + 1][c] && dist[0][l][c] < dist[0][l + 1][c])
			{
				dist[0][l + 1][c] = dist[0][l][c];
				que.push_front(make_tuple(0, l + 1, c));
			}
			if (l < N - 1 && dist[0][l][c] + 1 < dist[1][l + 1][c])
			{
				dist[1][l + 1][c] = dist[0][l][c] + 1;
				que.push_back(make_tuple(1, l + 1, c));
			}
			if (c < N - 1 && S[l][c] == S[l][c + 1] && dist[0][l][c] < dist[0][l][c + 1])
			{
				dist[0][l][c + 1] = dist[0][l][c];
				que.push_front(make_tuple(0, l, c + 1));
			}
			if (c < N - 1 && dist[0][l][c] + 1 < dist[1][l][c + 1])
			{
				dist[1][l][c + 1] = dist[0][l][c] + 1;
				que.push_back(make_tuple(1, l, c + 1));
			}
		}
	}
	return dist[0][get<1>(goal)][get<2>(goal)];
}


int main()
{
	ll N;
	cin >> N;
	vector<string> S(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	ll ans = sub(N, S, make_tuple(0, 0, 0), make_tuple(0, N - 1, N - 1), 'R');
	ans += sub(N, S, make_tuple(0, N - 1, 0), make_tuple(0, 0, N - 1), 'B');
	cout << ans << endl;

}
