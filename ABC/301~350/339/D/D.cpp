#include <bits/stdc++.h>
using namespace std;

#define inf 100000000

int main()
{
	int					N;
	cin >> N;
	vector<string>		s(N);
	queue<int>			q;
	int					i1;
	int					i2;
	int					j1;
	int					j2;
	int					ni1;
	int					ni2;
	int					nj1;
	int					nj2;
	vector 				state(N, vector(N, vector(N, vector(N, inf))));

	for (int i = 0; i < N; i++)
		cin >> s[i];
	int now = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j ++)
		{
			if (s[i][j] == 'P' && now == -1)
			{
				i1 = i;
				j1 = j;
				now = pow(N, 3) * i + pow(N, 2) * j;
			}
			else if (s[i][j] == 'P')
			{
				i2 = i;
				j2 = j;
				now += N * i + j;
			}
		}
	}
	state[i1][j1][i2][j2] = 0;
	q.push(now);
	while (!q.empty())
	{
		now = q.front(), q.pop();
		j2 = now % N, now /= N;
		i2 = now % N, now /= N;
		j1 = now % N, now /= N;
		i1 = now % N, now /= N;
		if (i1 == i2 && j1 == j2)
			break;
		if (state[i1 - (i1 > 0 && s[i1 - 1][j1] != '#')][j1][i2 - (i2 > 0 && s[i2 - 1][j2] != '#')][j2] == inf)
		{
			ni1 = i1 - (i1 > 0 && s[i1 - 1][j1] != '#');
			nj1 = j1;
			ni2 = i2 - (i2 > 0 && s[i2 - 1][j2] != '#');
			nj2 = j2;
			state[ni1][nj1][ni2][nj2] = state[i1][j1][i2][j2] + 1;
			q.push(ni1 * pow(N, 3) + nj1 * pow(N, 2) + ni2 * N + nj2);
		}
		if (state[i1][j1 - (j1 > 0 && s[i1][j1 - 1] != '#')][i2][j2 - (j2 > 0 && s[i2][j2 - 1] != '#')] == inf)
		{
			ni1 = i1;
			nj1 = j1 - (j1 > 0 && s[i1][j1 - 1] != '#');
			ni2 = i2;
			nj2 = j2 - (j2 > 0 && s[i2][j2 - 1] != '#');
			state[ni1][nj1][ni2][nj2] = state[i1][j1][i2][j2] + 1;
			q.push(ni1 * pow(N, 3) + nj1 * pow(N, 2) + ni2 * N + nj2);
		}
		if (state[i1 + (i1 < N - 1 && s[i1 + 1][j1] != '#')][j1][i2 + (i2 < N - 1 && s[i2 + 1][j2] != '#')][j2] == inf)
		{
			ni1 = i1 + (i1 < N - 1 && s[i1 + 1][j1] != '#');
			nj1 = j1;
			ni2 = i2 + (i2 < N - 1 && s[i2 + 1][j2] != '#');
			nj2 = j2;
			state[ni1][nj1][ni2][nj2] = state[i1][j1][i2][j2] + 1;
			q.push(ni1 * pow(N, 3) + nj1 * pow(N, 2) + ni2 * N + nj2);
		}
		if (state[i1][j1 + (j1 < N - 1 && s[i1][j1 + 1] != '#')][i2][j2 + (j2 < N - 1 && s[i2][j2 + 1] != '#')] == inf)
		{
			ni1 = i1;
			nj1 = j1 + (j1 < N - 1 && s[i1][j1 + 1] != '#');
			ni2 = i2;
			nj2 = j2 + (j2 < N - 1 && s[i2][j2 + 1] != '#');
			state[ni1][nj1][ni2][nj2] = state[i1][j1][i2][j2] + 1;
			q.push(ni1 * pow(N, 3) + nj1 * pow(N, 2) + ni2 * N + nj2);
		}
	}

	int	ans = inf;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans = min(ans, state[i][j][i][j]);
		}
	}

	
	if (ans < inf)
		cout << ans << endl;
	else
		cout << -1 << endl;

}
