#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long A[5], P[5];
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> A[j];
		for (int j = 0; j < 5; j++)
			cin >> P[j];
		long long sum = 0;
		for (int i = 0; i < 5; i++)
			sum += (i - 2) * A[i];
		if (sum > 0)
		{
			cout << 0 << endl;
			continue;
		}
		long cand1, cand2, cand3;
		cand1 = -sum * P[3];
		cand2 = (-sum - (-sum / 2 * 2)) * P[3] + (-sum / 2) * P[4];
		cand3 = (max(0ll, (-sum - (((-sum + 1) / 2) * 2)))) * P[3] + ((-sum + 1) / 2) * P[4];
		
		cout << min(min(cand1, cand2), cand3) << endl;
	}
}
