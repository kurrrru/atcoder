#include <stdio.h>
#include <stdlib.h>

#define MOD  1999999973ULL

int	compare(const void *a, const void *b) {
    return (*(unsigned long long*)a - *(unsigned long long*)b);
}

int	binary_search(unsigned long long *array, unsigned long long val, int N)
{
	int	left;
	int	right;
	int mid;

	left = -1;
	right = N;
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (array[mid] < val)
			left = mid;
		else
			right = mid;
	}
	return (right);
}

unsigned long long	myatoi(char *s)
{
	unsigned long long ret;

	ret = 0;
	while (*s)
		ret = (ret * 10ULL + *s++ - '0') % MOD;
	return (ret);
}


int	main()
{
	int					N;
	char				s[1000][1001];
	unsigned long long	A[1000];
	long long			ans;
	int					same_num;

	(void)scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		(void)scanf("%s", s[i]);
		A[i] = myatoi(s[i]);
	}
	qsort(A, N, sizeof(unsigned long long), compare);

	ans = 0LL;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{			
			same_num = binary_search(A, (A[i] * A[j] + 1ULL) % MOD, N) - binary_search(A, (A[i] * A[j]) % MOD, N);
			if (i == j)
				ans += same_num;
			else
				ans += same_num * 2;
		}
	}
	printf("%d\n", ans);
}
