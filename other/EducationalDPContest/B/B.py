N,K=map(int,input().split())
h=list(map(int,input().split()))

dp=[float("inf") for _ in range(N)]
dp[0]=0
for i in range(N-1):
    for j in range(1,K+1):
        if i+j>=N: break
        dp[i+j]=min(dp[i+j],dp[i]+abs(h[i+j]-h[i]))
print(dp[N-1])