#include <bits/stdc++.h>
using namespace std;



int main()
{
	int H, W, N;
	cin >> H >> W >> N;
	string T;
	cin >> T;
	vector<string> S(H);
	for (auto &e : S)
		cin >> e;
	int x, y, k;
	int ans = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			x = i, y = j;
			if (S[x][y] == '#')
				continue ;
			k = -1;
			while (T[++k])
			{
				if (T[k] == 'L')
					y -= 1;
				else if (T[k] == 'R')
					y += 1;
				else if (T[k] == 'U')
					x -= 1;
				else if (T[k] == 'D')
					x += 1;
				if (x < 0 || x >= H || y < 0 || y >= W || S[x][y] == '#')
					break ;
			}
			if (!T[k])
				ans++;
		}
	}
	cout << ans << endl;
}