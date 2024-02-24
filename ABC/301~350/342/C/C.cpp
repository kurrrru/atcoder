#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	int Q;
	cin >> Q;
	char c[Q], d[Q];
	vector<char> memo(256, 0);
	vector<char> memo2[256];
	for (char i = 'a'; i <= 'z'; i++)
	{
		memo2[i].push_back(i);
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> c[i] >> d[i];
		if (c[i] == d[i])
			continue;

		while (!memo2[c[i]].empty())
		{
			char x = memo2[c[i]].back();
			memo2[c[i]].pop_back();
			memo2[d[i]].push_back(x);
			memo[x] = d[i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (memo[S[i]])
			S[i] = memo[S[i]];
	}
	cout << S << endl;
}