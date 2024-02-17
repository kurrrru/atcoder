#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using S = long long;

S op(S a, S b){ return a + b; }
S e(){ return 0; }

int main()
{
	int N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	vector<S> ok(N);
	for (int i = 0; i < N - 1; i++)
		ok[i] = (s[i] != s[i+1]);
	ok[N - 1] = 1;

	atcoder::segtree<S, op, e> seg(ok);
	int x, L, R;
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> L >> R;
		L--, R--;
		if (x == 1)
		{
			if (L > 0)
				seg.set(L - 1, 1 - seg.get(L - 1));
			seg.set(R, 1 - seg.get(R));
		}
		else
		{
			if (seg.prod(L, R) == R - L)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}
