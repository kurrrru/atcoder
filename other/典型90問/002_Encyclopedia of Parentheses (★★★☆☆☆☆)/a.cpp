// 002 - Encyclopedia of Parentheses (★★★☆☆☆☆)

// 深さ優先探索

# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n % 2 == 1) return 0;
    
    int m = n / 2;
    stack<tuple<string, int, int>> a;
    a.push(make_tuple("("s, 1, 0));
    string x;
    int s, t;
    tuple<string, int, int> tmp;
    while (!a.empty()) {
        tmp = a.top();
        a.pop();
        x = get<0>(tmp);
        s = get<1>(tmp);
        t = get<2>(tmp);
        if ((s == m) and (t == m)) {
            cout << x << endl;
        } else if (s == m) {
            cout << x + string(m - t, ')') << endl;
        } else if (s == t) {
            a.push(make_tuple(x + "("s, s + 1, t));
        } else {
            a.push(make_tuple(x + ")"s, s, t + 1));
            a.push(make_tuple(x + "("s, s + 1, t));
        }
    }
    return 0;
}