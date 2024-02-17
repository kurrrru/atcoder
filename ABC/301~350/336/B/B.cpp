#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a = N & (-N);
	cout << (int)log2(a) << endl;
}