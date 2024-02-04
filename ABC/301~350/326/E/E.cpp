#include<iostream>

using namespace std;

long long int MOD = 998244353;

template <typename Number>
Number extgcd(Number a, Number b, Number &x, Number &y) {
/*
ax+by=d
a=b*(a/b) + a%b
(b*(a/b) + a%b)x + by=d
b ((a/b)x + y) + a%b x  = d 
*/
    Number d=a;
    if (b==0) {
        x=1;
        y=0;
        return d;
    }
    d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

void solve(int N, int* &A) {
    long long int* dp=(long long int*)malloc(N * sizeof(long long int));
    long long int* ac=(long long int*)malloc(N * sizeof(long long int));
    dp[N-1] = A[N-1];
    ac[N-1] = A[N-1];
    for (int i=0; i<N-1; ++i) {
        dp[i]=0;
        ac[i]=0;
    }
    long long int x=0,y=0;
    extgcd<long long int>(N,MOD,x,y);
    long long int n_inv=x;
    for (int i=N-2; i>=0; --i) {
        dp[i]=A[i]+ac[i+1]*n_inv;
        dp[i]%=MOD;
        ac[i]=ac[i+1]+dp[i];
        ac[i]%=MOD;
    }
    long long int ans=0;
    for (int i=0;i<N;i++) {
        ans+=dp[i]*n_inv%MOD;
        ans%=MOD;
    }
    cout << ans << endl;
    free(dp);
    free(ac);
}

int main() {
    int N; 
    cin >> N;
    int* A=(int*)malloc(N * sizeof(int));
    for (int i=0;i<N;i++) cin >> A[i];
    solve(N,A);
    free(A);
}