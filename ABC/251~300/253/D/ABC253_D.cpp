#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,s,an,bn,abn,as,bs,ab_s;
    cin >> n >> a >> b;
    an = n/a;
    bn = n/b;
    abn = n/(a*b);
    s = n*(n+1)/2;
    as = a*an*(an+1)/2;
    bs = b*bn*(bn+1)/2;
    ab_s = a*b*abn*(abn+1)/2;
    cout << s-as-bs+ab_s;
}