#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;

struct LazySegmentTreeNode {
    long long sum; // 区間の和
    long long lazy; // 遅延評価用の値（区間更新で加算される値）

    LazySegmentTreeNode() : sum(0), lazy(0) {}
};

class LazySegmentTree {
private:
    vector<LazySegmentTreeNode> tree;
    vector<long long> A; // 元の配列
    int n;

    // ノード番号がkのノードを根とする区間の和を計算
    long long query(int k, int left, int right, int l, int r) {
        propagate(k, left, right);
        if (r < left || right < l) return 0; // 区間が無効
        if (l <= left && right <= r) return tree[k].sum; // ノードが完全に区間を含む
        int mid = (left + right) / 2;
        return query(2 * k, left, mid, l, r) + query(2 * k + 1, mid + 1, right, l, r);
    }

    // ノード番号がkのノードを根とする区間に対して、遅延評価を行う
    void propagate(int k, int left, int right) {
        if (tree[k].lazy != 0) {
            tree[k].sum += tree[k].lazy * (right - left + 1);
            if (left != right) {
                tree[2 * k].lazy += tree[k].lazy;
                tree[2 * k + 1].lazy += tree[k].lazy;
            }
            tree[k].lazy = 0;
        }
    }

    // ノード番号がkのノードを根とする区間の和を更新
    void update(int k, int left, int right, int l, int r, long long value) {
        propagate(k, left, right);
        if (r < left || right < l) return; // 区間が無効
        if (l <= left && right <= r) {
            tree[k].lazy += value;
            propagate(k, left, right);
            return;
        }
        int mid = (left + right) / 2;
        update(2 * k, left, mid, l, r, value);
        update(2 * k + 1, mid + 1, right, l, r, value);
        tree[k].sum = tree[2 * k].sum + tree[2 * k + 1].sum;
    }

public:
    LazySegmentTree(const vector<long long>& _A) {
        A = _A;
        n = A.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int k, int left, int right) {
        if (left == right) {
            tree[k].sum = A[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * k, left, mid);
        build(2 * k + 1, mid + 1, right);
        tree[k].sum = tree[2 * k].sum + tree[2 * k + 1].sum;
    }

    // 区間 [l, r] に値 value を加算する
    void add(int l, int r, long long value) {
        update(1, 0, n - 1, l, r, value);
    }

    // 区間 [l, r] の和を求める
    long long sum(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // index 番目の要素の値を取得する
    long long get(int index) {
        return sum(index, index);
    }
};


int main()
{
	int N, M;
	cin >> N >> M;
	vector<long long> A(N);
	vector<int> B(M);

	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
	}

	long long C;
	LazySegmentTree tree(A);
	for (int i = 0; i < M; i++)
	{
		C = tree.get(B[i]);
		tree.add(B[i], B[i], -C);
		tree.add(0, N - 1, C / N);
		if (B[i] < N - 1)
			tree.add(B[i] + 1, min(B[i] + C % N, (long long) N - 1), 1);
		if (B[i] + C % N > N - 1)
			tree.add(0, B[i] + C % N - N, 1);
	}
	cout << tree.get(0);
	for (int i = 1; i < N; i++)
	{
		cout << " " << tree.get(i);
	}
	cout << endl;
}