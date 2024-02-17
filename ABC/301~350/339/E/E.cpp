#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
int MAX_A = 500000;

int main()
{
	int	N, D;
	cin >> N >> D;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	vector<S> v(MAX_A + 2, 0); 
	atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
	for (int e : A)
		seg.set(e, seg.prod(max(e - D, 1), min(e + D, MAX_A) + 1) + 1);
	cout << seg.all_prod() << endl;
}
