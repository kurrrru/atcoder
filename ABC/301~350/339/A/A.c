#include <stdio.h>

int	main()
{
	char	s[101];
	int		i;
	int		cnt;

	scanf("%s", s);
	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == '.')
			cnt = 0;
		else
			cnt++;
	}
	printf("%s\n", s + i -cnt);
}