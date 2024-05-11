#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int c = 0;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (c + A[i] <= K)
			c+= A[i];
		else
		{
			c = A[i];
			ans++;
		}
	}
	cout << ans + 1<< endl;

}