#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> H(N);
	cin >> H[0];
	for (int i = 1; i < N; i++)
	{
		cin >> H[i];
		if (H[0] < H[i])
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}