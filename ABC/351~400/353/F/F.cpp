#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long K, Sx, Sy, Tx, Ty;
	cin >> K >> Sx >> Sy >> Tx >> Ty;
	if (Sx > Tx)
	{
		swap(Sx, Tx);
		swap(Sy, Ty);
	}
	if (Sx < 0)
	{
		Sx -= 2 * K * (Sx / (2 * K) - 1);
	}
	else
	{
		Sx %= 2 * K;
	}
	if (Tx < 0)
	{
		Tx -= 2 * K * (Tx / (2 * K) - 1);
	}
	else
	{
		Tx %= 2 * K;
	}

	if (Sy > Ty)
	{
		Sy = K - Sy;
		Ty = K - Ty;
	}
	if (Sy < 0)
	{
		Sy -= 2 * K * (Sy / (2 * K) - 1);
	}
	else
	{
		Sy %= 2 * K;
	}
	if (Ty < 0)
	{
		Ty -= 2 * K * (Ty / (2 * K) - 1);
	}
	else
	{
		Ty %= 2 * K;
	}
	cout << Sx << " " << Sy << " " << Tx << " " << Ty << endl;
	long long ans = 0;
	long long a = Tx / (2 * K), b = Ty / (2 * K);
	if (a == b)
	{
		ans += (a - 1) * (2 * K + 1);
	}
	else if (a > b)
	{
		ans += (b - 1) * (2 * K + 1);
		ans += (a - b) * (K + 1);
	}
	else
	{
		ans += (a - 1) * (2 * K + 1);
		ans += (b - a) * (K + 1);
	}
	if (Sx >= K && Sy >= K)
	{
		ans += (2 * K - 1) - Sx + (2 * K - 1) - Sy;
	}
	else if (Sx >= K)
	{
		ans += K;
	}
	else if (Sy >= K)
	{
		ans += K;
	}
	else
	{
		ans += (K + 1) + (K - 1 - Sx) + (K - 1 - Sy);
	}
	Tx %= 2 * K;
	Ty %= 2 * K;
	if (Tx >= K && Ty >= K)
	{
		ans += (K + 1) + Tx + Ty - 2 * K;
	}
	else if (Tx >= K)
	{
		ans += K + 1;
	}
	else if (Ty >= K)
	{
		ans += K + 1;
	}
	else
	{
		ans += Tx + Ty + 1;
	}
	cout << ans << endl;

}