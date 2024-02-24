#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; i++)
		cin >> P[i];
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (find(P.begin(), P.end(), a) < find(P.begin(), P.end(), b))
			cout << a << endl;
		else
			cout << b << endl;
	}

}