#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int state[60][60][60][60];


int dfs(int i1, int j1, int i2, int j2, int cnt)
{
	if (state[i1][j1][i2][j2] == 0)
		state[i1][j1][i2][j2] = cnt;
	else
		state[i1][j1][i2][j2] = 1;
}

int main()
{
	int N;
	char s[60][60];
	queue<int> q;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", s[i]);
	int now = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j =0; j < N; j ++)
		{
			if (s[i][j] == 'P' && now == 0)
			{
				now = 216000 * i + 3600 * j;
			}
			else if (s[i][j] == 'P')
				now += 60 * i + j;
		}
	}
	int i1, i2, j1, j2;
	q.push(now);
	while (!q.empty())
	{
		now = q.front(), q.pop();
		j2 = now %60, now/=60;
		i2 = now %60, now/=60;
		j1 = now %60, now/=60;
		i1 = now %60, now/=60;
		if (i1 == i2 && j1 == j2)
			break;
	}
	printf("%d\n", state[i1][j1][i2][j2]);

}