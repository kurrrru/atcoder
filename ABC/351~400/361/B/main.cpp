#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cross(ll a, ll b, ll c, ll d)
{
	return (a < c && c < b) || (a < d && d < b) || (c < a && a < d) || (c < b && b < d); 
}

int main()
{
	vector<ll> A(6);
	for (ll i = 0; i < 6; i++) cin >> A[i];
	vector<ll> B(6);
	for (ll i = 0; i < 6; i++) cin >> B[i];
	if (cross(A[0], A[3], B[0], B[3]) && cross(A[1], A[4], B[1], B[4]) && cross(A[2], A[5], B[2], B[5]))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
