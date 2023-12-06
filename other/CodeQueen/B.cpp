#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,x,y,k;
    cin >> N;
    vector<vector<bool>> M(N,vector<bool>(N,true));

    for (int i=0;i<N-1;i++) {
        cin >> x >> y;
        M.at(x-1).at(y-1)=false;
        x--;
        y--;
        for (int di=-1; di<2; di++) {
            for (int dj=-1; dj<2; dj++) {
                if (di==0 && dj==0) {
                    continue;
                }
                k=1;
                while (x+di*k>=0 && x+di*k<N && y+dj*k>=0 && y+dj*k<N) {
                    M.at(x+di*k).at(y+dj*k)=false;
                    k++;
                }
            }
        }
    }
    for (int i=0;i<N;i++) {
        for (int j=0; j<N;  j++) {
            if (M.at(i).at(j)) {
                cout << i+1 << j+1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}