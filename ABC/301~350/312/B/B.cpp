#include<bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i=0; i<N; i++) cin >> S.at(i);
    
    int f=0;
    for (int a=0; a<N-8; a++) {
        for (int b=0; b<M-8; b++) {
            f=0;
            for (int i=0; i<9; i++) {
                for (int j=0; j<9; j++) {
                    if (i<3 && j<3 && S.at(a+i).at(b+j)!='#') {
                        f=1;
                        break;
                    } else if (i>=6 && j>=6 && S.at(a+i).at(b+j)!='#') {
                        f=1;
                        break;
                    } else if (((i==5 && j>=5) || (i>=5 && j==5) || (i==3 && j<=3) || (i<=3 && j==3)) && S.at(a+i).at(b+j)!='.') {
                        f=1;
                        break;
                    }
                }
                if (f==1) break;
            } 
            if (f==0) cout << a+1 << " " << b+1 << endl;
        }
    }
}