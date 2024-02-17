#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	long long ret = 0;
	long long digit = 1;
	N--;
	while (N > 0)
	{
		ret += digit * (N % 5) * 2;
		N /= 5;
		digit *= 10;
	}
	cout << ret << endl;
}