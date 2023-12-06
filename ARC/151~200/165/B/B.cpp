#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> P(N,0), L1(N,0), L2(N,0);
    for (int i=0; i<N; i++) cin >> P.at(i);
    multiset<int> s;
    int a=-1;
    for (int i=N-K;i<N;i++) {
        s.insert(P[i]);
    }
    int nowlast=0;
    for (int i=N-K;i>-1;i--) {
        if (i!=N-K) {
            s.erase(P[i+K]);
            s.insert(P[i]);
        }
        int j=0;
        auto it=s.begin();
        for (;j<K;j++) {
            // for (int i=0;i<j;i++) ++it;
            if (P[i+j]!=*it) {
                L1[i]=i+j;
                L2[i]=*it;
                nowlast=i+j;
                break;
            }
            ++it;
        }
        if (j==K) {
            a=i;
            break;
        }
        if (i+K<nowlast) break;
        if (i<N-K and L1[i]<nowlast) break;
    }
    if (a==-1) {
        int m=-1,t=0;
        for (int i=0;i<N-K+1;i++) {
            if (L1[i]>m) {
                m=L1[i];
                t=L2[i];
                a=i;
            } else if (L1[i]==m && L2[i]>t) {
                t=L2[i];
                a=i;
            }
        }
    }
    sort(P.begin()+a,P.begin()+a+K);
    for (int i=0;i<N-1;i++) {
        cout << P[i] << " ";
    }
    cout << P[N-1] << endl;
}