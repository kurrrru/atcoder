#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (A[i] % K == 0)
			cout << A[i] / K << " ";
	}
	cout << endl;
}