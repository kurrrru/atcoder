// 003 - Longest Circular Road (★★★★☆☆☆)

// 木の直径を求める

# include <bits/stdc++.h>
using namespace std;

pair<int, int> farthest(int s, vector<vector<int>> e, int n) {
    stack<int> stack;
    vector<int> d(n, -1);
    d.at(s) = 0;
    int argmax = 0;
    int max = 0;


    for (int v: e.at(s)) {
        stack.push(v);
        d.at(v) = 1;
        argmax = v;
    }
    max = 1;

    int t;
    
    while (!stack.empty()) {
        t = stack.top();
        stack.pop();
        for (int v: e.at(t)) {
            if (d.at(v) == -1) {
                d.at(v) = d.at(t) + 1;
                stack.push(v);
                if (d.at(v) > max) {
                    max = d.at(v);
                    argmax = v;
                }

            }
        }
    }
    
    return make_pair(argmax, max);
}

int main() { 
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    
    int a,b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        e.at(a-1).push_back(b-1);
        e.at(b-1).push_back(a-1);
    }

    int s = 0;
    int u = get<0>(farthest(s, e, n));
    int d = get<1>(farthest(u, e, n));

    cout << d + 1 << endl;
    return 0;
}

