#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N;
	cin >> N;
	vector<string> S(N);
	vector<ll> C(N);
	ll T = 0;
	for (ll i = 0; i < N; i++)
	{
		cin >> S[i] >> C[i];
		T += C[i];
	}
	sort(S.begin(), S.end());
	cout << S[T % N] << endl;
}