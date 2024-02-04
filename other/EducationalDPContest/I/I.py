N=int(input())
p=list(map(float,input().split()))

dp=[[0 for _ in range(N+1)] for _ in range(N+1)]
dp[0][0]=1
for i in range(N):
    for j in range(N):
        dp[i+1][j+1]+=p[i]*dp[i][j]
        dp[i+1][j]+=(1-p[i])*dp[i][j]
print(sum(dp[N][(N+1)//2::]))