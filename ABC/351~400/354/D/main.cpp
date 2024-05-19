#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll area[5][3] = {{0, 0, 0}, {0, 2, 3}, {0, 3, 6}, {0, 3, 7}, {0, 4, 8}};

ll area_calc(ll X, ll Y)
{
	ll ans = 0;
	ans += (X / 4) * (Y / 2) * area[4][2];
	ans += (X / 4) * area[4][Y % 2];
	ans += (Y / 2) * area[X % 4][2];
	ans += area[X % 4][Y % 2];
	return ans;
}

int main()
{
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	ll ans = 0;
	C += abs(A) * 4;
	A += abs(A) * 4;
	D += abs(B) * 2;
	B += abs(B) * 2;

	ans = area_calc(C, D) - area_calc(A, D) - area_calc(C, B) + area_calc(A, B);
	cout << ans << endl;
}