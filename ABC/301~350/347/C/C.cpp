#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, A, B;
	cin >> N >> A >> B;
	vector<long long> D(N);
	for (long long i = 0; i < N; i++)
	{
		cin >> D[i];
		D[i] %= (A + B);
	}
	sort(D.begin(), D.end());
	for (int i = 0; i < N; i++)
	{
		D.push_back(D[i] + A + B);
	}

	long long min_d = 1e18;
	for (long long i = 0; i < N; i++)
	{
		min_d = min(min_d, D[i + N - 1] - D[i]);
	}
	if (min_d < A)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}