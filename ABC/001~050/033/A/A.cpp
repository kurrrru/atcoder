#include <bits/stdc++.h>
using namespace std;

int main()
{
	string N;
	cin >> N;
	cout << ((N[0] == N[1] && N[1] == N[2] && N[2] == N[3]) ? "SAME" : "DIFFERENT") << endl;
}