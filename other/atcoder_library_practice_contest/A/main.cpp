#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using namespace std;

int main() {
	int N, Q, t, u, v;
	cin >> N >> Q;
	atcoder::dsu dsu(N);
	for (int i = 0; i < Q; i++) {
		cin >> t >> u >> v;
		if (t == 0)
			dsu.merge(u, v);
		else if (t == 1)
			cout << (int)dsu.same(u, v) << endl;
	}
}