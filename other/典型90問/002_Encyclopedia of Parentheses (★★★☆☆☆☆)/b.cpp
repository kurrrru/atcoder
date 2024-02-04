// 002 - Encyclopedia of Parentheses (★★★☆☆☆☆)

// bit全探索
// 0を"("、1を")"と対応させる

# include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int score;
    string s;

    for (int i = 0; i < 1 << n; i++) {
        score = 0;
        s = ""s;
        for (int j = n-1; j >= 0; j--) {
            if ((i & (1 << j)) == 0) {
                score += 1;
                s = s + "("s;
            } else {
                score -= 1;
                s = s + ")"s;
                if (score < 0) break;
            } 
        }
        if (score == 0) {
            cout << s << endl;
        }
    }
    return 0;

}