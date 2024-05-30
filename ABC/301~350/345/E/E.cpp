#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using S = long long;
// using F = long long;

const S INF = 8e18;
// const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
// S mapping(F f, S x){ return (f == ID ? x : f); }
// F composition(F f, F g){ return (f == ID ? g : f); }
// F id(){ return ID; }

int main()
{
	long long N, K;
	cin >> N >> K;
	vector<long long> C(N);
	vector<long long> V(N);
	for (int i = 0; i < N; i++)
		cin >> C[i] >> V[i];
	vector<long long> zero(N + 1, 0);
	atcoder::segtree<S, op, e> seg(zero);

}