#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using S = ll;
S op1(S a, S b) { return a + b; }
S e1() { return 0; }

S op2(S a, S b) { return max(a, b); }
S e2() { return 0; }
bool f(S v) { return v < 2; }

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	for (ll i = 0; i < N; i++)
		cin >> B[i];
	atcoder::segtree<S, op1, e1> seg1(A);
	atcoder::segtree<S, op2, e2> seg2(B);
	ll Q;
	cin >> Q;
	while (Q--)
	{
		ll op;
		cin >> op;
		if (op == 1)
		{
			ll i, x;
			cin >> i >> x;
			seg1.set(i - 1, x);
		}
		else if (op == 2)
		{
			ll i, x;
			cin >> i >> x;
			seg2.set(i - 1, x);
		}
		else if (op == 3)
		{
			ll l, r;
			cin >> l >> r;
			--l;
			--r;
			ll v = seg1.get(l);
			while (l < r)
			{
				ll j = min(r, (ll)seg2.max_right<f>(l + 1));
				v += seg1.prod(l + 1, j);
				v = max(v + seg1.get(j), v * seg2.get(j));
				l = j;
			}
			cout << v << endl;
		}
	}
}
