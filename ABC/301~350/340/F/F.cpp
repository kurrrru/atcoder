#include <bits/stdc++.h>
using namespace std;

long long extgcd(long long a,long long b,long long& x,long long& y) {
    long long d=a;
    if (b!=0) {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    } else {
        x=1;y=0;
    }
    return d;
}

int main()
{
	long long X, Y;
	cin >> X >> Y;
	long long A, B, d;
	d = extgcd(X, -Y, B, A);
	if (abs(d) > 2)
	{
		cout << -1 << endl;
		return (0);
	}
	A *= 2 / d;
	B *= 2 / d;

	cout <<  A  << " " << B << endl;


}