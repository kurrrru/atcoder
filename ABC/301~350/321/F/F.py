Q,K=map(int,input().split())
dp=[0]*(K+1)
dp[0]=1
MOD=998244353
for _ in range(Q):
    op,x=input().split()
    x=int(x)
    if op=="+":
        for j in range(K-x,-1,-1):
            dp[j+x]+=dp[j]
            dp[j+x]%=MOD
    else:
        for j in range(K-x+1):
            dp[j+x]-=dp[j]
            dp[j+x]+=MOD
            dp[j+x]%=MOD
    print(dp[K])