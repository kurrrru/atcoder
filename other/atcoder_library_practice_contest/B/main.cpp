#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	ll A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	atcoder::fenwick_tree<ll> fw(N);
	for (int i = 0; i < N; i++) {
		fw.add(i, A[i]);
	}
	for (int i = 0; i < Q; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 0) {
			fw.add(x, y);
		} else {
			cout << fw.sum(x, y) << endl;
		}
	}
}