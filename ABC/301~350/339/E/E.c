#include <stdio.h>
int	dp[500001];

int main()
{
	int			N;
	int			D;
	int			A[500000];
	int			max_i;
	int			ans;

	(void)scanf("%d %d", &N, &D);
	for (int i = 0; i < N; i++)
		(void)scanf("%d", A + i);
	dp[0] = 1;
	ans = 0;
	for (int i = 1; i < N; i++)
	{
		max_i = 500000;
		for (int j = 0; j < i; j++)
		{
			if (A[i] - A[j] <= D && A[j] - A[i] <= D && dp[max_i] < dp[j])
				max_i = j;
		}
		dp[i] = dp[max_i] + 1;
		if (dp[i] > ans)
			ans = dp[i];
	}
	printf("%d\n", ans);
}
