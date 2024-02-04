N,K=map(int,input().split())
dp=[[0 for _ in range(2)] for _ in range(N)]
dp[0][1]=1
MOD=int(1e9+7)
for i in range(1,N):
    dp[i][0]=dp[i-1][0]+dp[i-1][1]
    if i<K-1:
        dp[i][1]=dp[i-1][0]+dp[i-1][1]
    elif i==K-1:
        dp[i][1]=dp[i-1][0]+dp[i-1][1]-1
    else:
        dp[i][1]=dp[i-1][0]+dp[i-1][1]-dp[i-K][0]
    dp[i][0]%=MOD
    dp[i][1]%=MOD    
print(dp[N-1][1])