#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	if (N == 1)
	{
		for (int i = 0; i < K; i++)
			cout << 1 << " \n"[i == K - 1];
		return 0;
	}
	vector<ll> numbers(N);
	for (int i = 0; i < N; i++)
		numbers[i] = i + 1;
	if (N % 2 == 1)
	{
		for (int i = 0; i < K; i++)
		{
			cout << (N + 1) / 2 << " ";
		}
		cout << (N + 1) / 2 - 1 << " ";
		for (int i = N; i >= 1; i--)
		{
			if (i == (N + 1) / 2)
				continue;
			if (i != (N + 1) / 2 - 1)
				cout << i << " \n"[i == 1 && K == 1];
			for (int j = 0; j < K - 1; j++)
			{
				cout << i << " \n"[j == K - 2 && i == 1];
			}
		}
	}
	else
	{
		cout << N / 2 << " ";
		for (int i = N; i >= 1; i--)
		{
			if (i != N / 2)
				cout << i << " \n"[i == 1 && K == 1];
			for (int j = 0; j < K - 1; j++)
			{
				cout << i << " \n"[j == K - 2 && i == 1];
			}
		}
	}
}

// S = (nk)! / (k!) ^ n