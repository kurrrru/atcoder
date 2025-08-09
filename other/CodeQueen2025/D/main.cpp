#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

#ifndef IMPLICIT_TREAP_HPP
#define IMPLICIT_TREAP_HPP

#include <iostream>
#include <cassert>
#include <vector>

namespace toolbox
{

namespace datastructure
{

namespace monoid_implicit_treap
{

struct monoid_range_add_range_min
{
	static long long query_op(long long a, long long b)
	{
		return (std::min(a, b));
	}
	static long long query_id()
	{
		return (2e18);
	}
	static long long update_op(long long a, long long b)
	{
		return (a + b);
	}
	static long long update_id()
	{
		return (0);
	}
	static long long apply(long long a, long long b, int len)
	{
		return (b == update_id() ? a : a + b);
	}
};

struct monoid_range_add_range_max
{
	static long long query_op(long long a, long long b)
	{
		return (std::max(a, b));
	}
	static long long query_id()
	{
		return (-2e18);
	}
	static long long update_op(long long a, long long b)
	{
		return (a + b);
	}
	static long long update_id()
	{
		return (0);
	}
	static long long apply(long long a, long long b, int len)
	{
		return (b == update_id() ? a : a + b);
	}
};

struct monoid_range_add_range_sum
{
	static long long query_op(long long a, long long b)
	{
		return (a + b);
	}
	static long long query_id()
	{
		return (0);
	}
	static long long update_op(long long a, long long b)
	{
		return (a + b);
	}
	static long long update_id()
	{
		return (0);
	}
	static long long apply(long long a, long long b, int len)
	{
		return (b == update_id() ? a : a + b * len);
	}
};

struct monoid_range_update_range_min
{
	static long long query_op(long long a, long long b)
	{
		return (std::min(a, b));
	}
	static long long query_id()
	{
		return (2e18);
	}
	static long long update_op(long long a, long long b)
	{
		return (b);
	}
	static long long update_id()
	{
		return (2e18);
	}
	static long long apply(long long a, long long b, int len)
	{
		return (b == update_id() ? a : b);
	}
};

struct monoid_range_update_range_max
{
	static long long query_op(long long a, long long b)
	{
		return (std::max(a, b));
	}
	static long long query_id()
	{
		return (-2e18);
	}
	static long long update_op(long long a, long long b)
	{
		return (b);
	}
	static long long update_id()
	{
		return (0);
	}
	static long long apply(long long a, long long b, int len)
	{
		return (b == update_id() ? a : b);
	}
};

struct monoid_range_update_range_sum
{
	static long long query_op(long long a, long long b)
	{
		return (a + b);
	}
	static long long query_id()
	{
		return (0);
	}
	static long long update_op(long long a, long long b)
	{
		return (b);
	}
	static long long update_id()
	{
		return (2e18);
	}
	static long long apply(long long a, long long b, int len)
	{
		return (b == update_id() ? a : b * len);
	}
};

} // namespace monoid_implicit_treap

template<typename S, class operations, unsigned int seed = 1>
struct implicit_treap
{
	implicit_treap() : _rnd(seed) {}
	implicit_treap(implicit_treap &) = delete;
	implicit_treap(implicit_treap &&) = delete;
	implicit_treap &operator=(implicit_treap &) = delete;
	implicit_treap &operator=(implicit_treap &&) = delete;
	~implicit_treap()
	{
		clear();
	}

	implicit_treap(std::vector<S> &vec) : _rnd(seed)
	{
		for (size_t i = 0; i < vec.size(); i++)
			insert(i, vec[i]);
	}
	implicit_treap(int size, S val) : _rnd(seed)
	{
		assert(size >= 0);
		for (int i = 0; i < size; i++)
			insert(i, val);
	}

	S query(int l, int r)
	{
		assert(0 <= l && l <= r && r <= size());
		return (query(_root, l, r));
	}

	void update(int l, int r, S val)
	{
		assert(0 <= l && l <= r && r <= size());
		update(_root, l, r, val);
	}

	S operator[](int pos)
	{
		assert(0 <= pos && pos < size());
		node *left;
		node *right;
		node *mid;
		split(_root, pos, left, right);
		split(right, 1, mid, right);
		S res = mid->_value;
		merge(right, mid, right);
		merge(_root, left, right);
		return (res);
	}

	void insert(int pos, S val)
	{
		insert(_root, pos, new node(val, _rnd.random()));
	}

	void erase(int pos)
	{
		assert(0 <= pos && pos < size());
		erase(_root, pos);
	}

	int size() const
	{
		if (!_root)
			return (0);
		return (cnt(_root));
	}

	// int lower_bound(int l, int r, S val)
	// {
	// 	return (lower_bound(_root, val));
	// }

	// int upper_bound(int l, int r, S val)
	// {
	// 	return (upper_bound(_root, val));
	// }

	void reverse(int l, int r)
	{
		assert(0 <= l && l <= r && r <= size());
		reverse(_root, l, r);
	}

	void rotate(int l, int m, int r)
	{
		assert(0 <= l && l <= m && m <= r && r <= size());
		rotate(_root, l, m, r);
	}

	void clear()
	{
		clear(_root);
		_root = nullptr;
	}

private:

	struct xorshift
	{
		unsigned int _state = 1;
		xorshift(unsigned int _seed): _state(_seed) {}
		unsigned int random()
		{
			_state ^= _state << 13;
			_state ^= _state >> 17;
			_state ^= _state << 5;
			return (_state);
		}
	} _rnd;

	struct node
	{
        S _value;
		S _acc;
		S _lazy;
        int _priority;
		int _cnt;
        bool _rev;
        node *_child[2];
        node(S val, int priority)
		{
			_value = val;
			_acc = operations::query_id();
			_lazy = operations::update_id();
			_priority = priority;
			_cnt = 1;
			_rev = false;
			_child[0] = nullptr;
			_child[1] = nullptr;
		}
    } *_root = nullptr;

	int cnt(node *t) const
	{
		if (!t)
			return (0);
		return (t->_cnt);
	}

	S acc(node *t) const
	{
		if (!t)
			return (operations::query_id());
		return (t->_acc);
	}

	void update(node *t)
	{
		if (!t)
			return;
		t->_cnt = 1 + cnt(t->_child[0]) + cnt(t->_child[1]);
		t->_acc = operations::query_op(operations::query_op(acc(t->_child[0]), t->_value), acc(t->_child[1]));
	}

	void pushup(node *t)
	{
		if (!t)
			return;
		update(t);
	}

	void pushdown(node *t)
	{
		if (!t)
			return;
		if (t->_rev)
		{
			std::swap(t->_child[0], t->_child[1]);
			if (t->_child[0])
				t->_child[0]->_rev ^= 1;
			if (t->_child[1])
				t->_child[1]->_rev ^= 1;
			t->_rev = false;
		}
		if (t->_lazy != operations::update_id())
		{
			if (t->_child[0])
			{
				t->_child[0]->_lazy = operations::update_op(t->_child[0]->_lazy, t->_lazy);
				t->_child[0]->_acc = operations::apply(t->_child[0]->_acc, t->_lazy, cnt(t->_child[0]));
			}
			if (t->_child[1])
			{
				t->_child[1]->_lazy = operations::update_op(t->_child[1]->_lazy, t->_lazy);
				t->_child[1]->_acc = operations::apply(t->_child[1]->_acc, t->_lazy, cnt(t->_child[1]));
			}
			t->_value = operations::apply(t->_value, t->_lazy, 1);
			t->_lazy = operations::update_id();
		}
	}

	void split(node *t, int key, node *&l, node *&r)
	{
		if (!t)
			l = r = nullptr;
		else
		{
			pushdown(t);
			int cur_key = cnt(t->_child[0]);
			if (key > cur_key)
			{
				l = t;
				split(t->_child[1], key - cur_key - 1, l->_child[1], r);
			}
			else
			{
				r = t;
				split(t->_child[0], key, l, r->_child[0]);
			}
			pushup(t);
		}
	}

	void merge(node *&t, node *l, node *r)
	{
		pushdown(l);
		pushdown(r);
		if (!l)
			t = r;
		else if (!r)
			t = l;
		else if (l->_priority > r->_priority)
		{
			t = l;
			merge(t->_child[1], l->_child[1], r);
		}
		else
		{
			t = r;
			merge(t->_child[0], l, r->_child[0]);
		}
		pushup(t);
	}

	void insert(node *&t, int key, node *item)
	{
		node *left;
		node *right;
		split(t, key, left, right);
		merge(left, left, item);
		merge(t, left, right);
	}

	void erase(node *&t, int key)
	{
		node *left;
		node *right;
		node *mid;
		split(t, key, left, right);
		split(right, 1, mid, right);
		merge(t, left, right);
	}

	void update(node *&t, int l, int r, S val)
	{
		if (l >= r)
			return ;
		node *left;
		node *right;
		node *mid;
		split(t, l, left, right);
		split(right, r - l, mid, right);
		mid->_lazy = operations::update_op(mid->_lazy, val);
		mid->_acc = operations::apply(mid->_acc, val, cnt(mid));
		merge(right, mid, right);
		merge(t, left, right);
	}

	S query(node *t, int l, int r)
	{
		node *left;
		node *right;
		node *mid;
		split(t, l, left, right);
		split(right, r - l, mid, right);
		S res = operations::query_id();
		if (mid)
			res = mid->_acc;
		merge(right, mid, right);
		merge(t, left, right);
		return (res);
	}

	// int lower_bound(node *t, S val)
	// {
	// 	if (!t)
	// 		return (0);
	// 	pushdown(t);
	// 	if (t->_value >= val)
	// 		return (lower_bound(t->_child[0], val));
	// 	return (cnt(t->_child[0]) + 1 + lower_bound(t->_child[1], val));
	// }

	// int upper_bound(node *t, S val)
	// {
	// 	if (!t)
	// 		return (0);
	// 	pushdown(t);
	// 	if (t->_value > val)
	// 		return (upper_bound(t->_child[0], val));
	// 	return (cnt(t->_child[0]) + 1 + upper_bound(t->_child[1], val));
	// }

	void reverse(node *t, int l, int r)
	{
		if (l >= r)
			return ;
		node *left;
		node *right;
		node *mid;
		split(t, l, left, right);
		split(right, r - l, mid, right);
		mid->_rev ^= 1;
		merge(right, mid, right);
		merge(t, left, right);
	}

	void rotate(node *t, int l, int m, int r)
	{
		if (l >= m || m >= r)
			return ;
		reverse(t, l, r);
		reverse(t, l, l + r - m);
		reverse(t, l + r - m, r);
	}

	void clear(node *t)
	{
		if (!t)
			return;
		clear(t->_child[0]);
		clear(t->_child[1]);
		delete t;
	}
};

} // namespace datastructure

} // namespace toolbox

#endif


int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= K;
        // cout << A[i] << " \n"[i == N - 1];
    }
    vector<ll> acc(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        acc[i + 1] = acc[i] + A[i];
    }
    // for (ll i = 0; i <= N; i++) {
    //     cout << acc[i] << " \n"[i == N];
    // }
    toolbox::datastructure::implicit_treap<ll, toolbox::datastructure::monoid_implicit_treap::monoid_range_add_range_min> treap(acc);
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll left = i;
        ll right = N + 1;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (treap.query(mid, N + 1) <= acc[i])
                left = mid;
            else
                right = mid;
        }
        // cout << "i: " << i << ", left: " << left << ", right: " << right << endl;
        ans = max(ans, left - i);
    }
    cout << ans << endl;










    // ll ans = 0;
    // ll end = 0;
    // ll sum = 0;
    // for (ll start = 0; start < N; start++) {
    //     cout << "start: " << start << ", end: " << end << ", sum: " << sum << endl;
    //     while (end < N && sum <= 0) {
    //         sum += A[end];
    //         end++;
    //     }
    //     cout << "Updated end: " << end << ", sum: " << sum << endl;
    //     ans = max(ans, end - start);
    //     sum -= A[start];
    // }
    // cout << ans << endl;
}

// 0 -2 1 -1 0 1