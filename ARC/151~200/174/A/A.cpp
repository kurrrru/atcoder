#include <bits/stdc++.h>
using namespace std;

long long sum(long long a[], int N)
{
	long long s = 0;
	for (int i = 0; i < N; i++)
	{
		s += a[i];
	}
	return s;
}

int main()
{
	long long N, C;
	cin >> N >> C;
	long long a[N];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	long long acc[N + 1];
	acc[0] = 0;
	for (int i = 0; i < N; i++)
		acc[i + 1] = acc[i] + a[i];
	if (C == 1)
		cout << sum(a, N) << endl;
	else if (C > 1)
	{
		long long now_max, l, r;
		now_max = 0;
		l = 0;
		r = 0;
		while (r <= N)
		{
			if (acc[r] - acc[l] >= 0)
			{
				if (acc[r] - acc[l] > now_max)
					now_max = acc[r] - acc[l];
				r++;
			}
			else
				l = r;
		}
		cout << acc[N] + (C - 1) * now_max << endl;
	}
	else
	{
		long long now_min, l, r;
		now_min = 0;
		l = 0;
		r = 0;
		while (r <= N)
		{
			if (acc[r] - acc[l] <= 0)
			{
				if (acc[r] - acc[l] < now_min)
					now_min = acc[r] - acc[l];
				r++;
			}
			else
				l = r;
		}
		cout << acc[N] + (C - 1) * now_min << endl;
	}
	
}