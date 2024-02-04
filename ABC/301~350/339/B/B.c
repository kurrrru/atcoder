#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	H;
	int	W;
	int N;
	int **grid;
	int i, j, d, k;

	scanf("%d %d %d", &H, &W, &N);
	grid = (int **)calloc(H, sizeof(int *));
	i = -1;
	while (++i < H)
		grid[i] = (int *)calloc(W, sizeof(int));
	i = 0;
	j = 0;
	d = 0;
	k = -1;
	while (++k < N)
	{
		if (grid[i][j] == 0)
		{
			grid[i][j] = 1;
			switch (d)
			{
			case 0:
				j = (j + 1) % W;
				break;
			case 1:
				i = (i + 1) % H;
				break;
			case 2:
				j = (j - 1 + W) % W;
				break;
			case 3:
				i = (i - 1 + H) % H;
				break;
			default:
				break;
			}
			d = (d + 1) % 4;
		}
		else
		{
			grid[i][j] = 0;
			switch (d)
			{
			case 0:
				j = (j + W - 1) % W;
				break;
			case 1:
				i = (i + H - 1) % H;
				break;
			case 2:
				j = (j + 1) % W;
				break;
			case 3:
				i = (i + 1) % H;
				break;
			default:
				break;
			}
			d = (d + 3) % 4;
		}
	}
	i = -1;
	while (++i < H)
	{
		j = -1;
		while (++j < W)
		{
			if (grid[i][j] == 0)
				printf(".");
			else
				printf("#");
		}
		printf("\n");
	}
}