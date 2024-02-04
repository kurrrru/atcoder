#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int N;
	long long A[200000];
	long long min;
	long long now;

	(void)scanf("%d", &N);
	for (int i = 0; i < N; i++)
		(void)scanf("%lld", A + i);
	min = 0;
	now = 0;
	for (int i = 0; i < N; i++)
	{
		now += A[i];
		if (now < min)
			min = now;
	}
	printf("%lld\n", now - min);
}