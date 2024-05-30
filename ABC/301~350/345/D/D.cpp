#include <bits/stdc++.h>
using namespace std;

void printboard(vector<vector<int> > &board, int H, int W)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


bool backtrack(vector<vector<int> > &board, vector<pair<int, int>> &A, int H, int W, vector<bool> &used)
{
	// printboard(board, H, W);
	int x = H, y = W;
	bool breakflag = false;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == 0)
			{
				x = i;
				y = j;
				breakflag = true;
				break;
			}
		}
		if (breakflag)
			break;
	}
	if (x == H && y == W)
		return true;
	for (int i = 0; i < A.size(); i++)
	{
		if (used[i])
			continue;
		if (x + A[i].first <= H && y + A[i].second <= W)
		{
			bool flag = true;
			for (int j = 0; j < A[i].first; j++)
			{
				for (int k = 0; k < A[i].second; k++)
				{
					if (board[x + j][y + k] == 1)
						flag = false;
				}
			}
			if (flag)
			{
				for (int j = 0; j < A[i].first; j++)
				{
					for (int k = 0; k < A[i].second; k++)
					{
						board[x + j][y + k] = 1;
					}
				}
				used[i] = true;
				if (backtrack(board, A, H, W, used))
					return true;
				for (int j = 0; j < A[i].first; j++)
				{
					for (int k = 0; k < A[i].second; k++)
					{
						board[x + j][y + k] = 0;
					}
				}
				used[i] = false;
			}
		}
		if (x + A[i].second <= H && y + A[i].first <= W)
		{
			bool flag = true;
			for (int j = 0; j < A[i].second; j++)
			{
				for (int k = 0; k < A[i].first; k++)
				{
					if (board[x + j][y + k] == 1)
						flag = false;
				}
			}
			if (flag)
			{
				for (int j = 0; j < A[i].second; j++)
				{
					for (int k = 0; k < A[i].first; k++)
					{
						board[x + j][y + k] = 1;
					}
				}
				used[i] = true;
				if (backtrack(board, A, H, W, used))
					return true;
				for (int j = 0; j < A[i].second; j++)
				{
					for (int k = 0; k < A[i].first; k++)
					{
						board[x + j][y + k] = 0;
					}
				}
				used[i] = false;
			}
		}
	}
	return false;
}

int main()
{
	int N, H, W;
	cin >> N >> H >> W;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i].first >> A[i].second;
	vector<vector<int> > board(H, vector<int>(W, 0));
	vector<bool> used(N, false);
	if (backtrack(board, A, H, W, used))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}