#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int N;
	cin >> N;
	vector<ll> A(N), S(N - 1), T(N - 1);

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N - 1; i++)
		cin >> S[i] >> T[i];
	for (int i = 0; i < N - 1; i++)
	{
		A[i + 1] += A[i] / S[i] * T[i];
	}
	cout << A[N - 1] << endl;
}