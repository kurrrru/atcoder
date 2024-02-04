// 001-Yokan Party (★★★★☆☆☆)

// 最小値の最大値を求める問題は、「2分探索」を行う。

# include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    int _a[n+1], a[n+1];
    _a[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> _a[i];
        a[i-1] = _a[i] - _a[i-1];
    }
    a[n] = l - _a[n];

    int left = 0, right = l;
    int mid = (left + right) / 2;
    int cutnum, length;

    while (left < right - 1) {
        cutnum = 0;
        length = 0;
        for (int i = 0; i < n + 1; i++) {
            length += a[i];
            if (length >= mid) {
                if (cutnum == k) continue;
                length = 0;
                cutnum += 1;
            }
        }
        if ((cutnum < k) || (length < mid)) right = mid;
        else left = mid;
        mid = (left + right) / 2;
    }
    cout << mid << endl;
    return 0;
}