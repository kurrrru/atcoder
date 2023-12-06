#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,D;
    cin >> N >> D;
    int x,y;
    vector<pair<int,int>> v(N);
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        v.at(i)={x,y};
    }
    vector<vector<int>> Q(N);
    int x1,x2,y1,y2;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            x1=v.at(i).first;
            y1=v.at(i).second;
            x2=v.at(j).first;
            y2=v.at(j).second;
            if (pow(x1-x2,2)+pow(y1-y2,2)<=pow(D,2)) {
                Q.at(i).push_back(j);
                Q.at(j).push_back(i);
            }
        }
    }
    vector<bool> F(N,false);
    stack<int> s;
    s.push(0);
    int a;
    while (! s.empty()) {
        a=s.top();
        s.pop();
        F.at(a)=true;
        for (int i=0; i<Q.at(a).size(); i++) {
            if (! F.at(Q.at(a).at(i))) {
                s.push(Q.at(a).at(i));
            }
        }
    }

    for (int i=0; i<N; i++) {
        if (F.at(i)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}