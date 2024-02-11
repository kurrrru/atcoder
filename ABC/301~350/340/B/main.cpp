#include <bits/stdc++.h>
using namespace std;

int main()
{
	int Q, k, n;
	cin >> Q;
	vector<int> vec;
	for (int i = 0; i < Q; i++)
	{
		cin >> k >> n;
		if (k == 1)
			vec.push_back(n);
		else
			cout << vec.at(vec.size() - n) << endl;
	}
}