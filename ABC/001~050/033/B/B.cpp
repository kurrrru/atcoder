#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string S[N];
	vector<int> P(N);
	for (int i = 0; i < N; i++)
		cin >> S[i] >> P[i];
	int max_id = 0, sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += P[i];
		if (P[i] > P[max_id])
			max_id = i;
	}
	if (P[max_id] * 2 > sum)
		cout << S[max_id] << endl;
	else
		cout << "atcoder" << endl;
}