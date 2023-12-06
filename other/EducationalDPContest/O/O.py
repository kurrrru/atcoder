N=int(input())
A=[[] for _ in range(N)]
MOD=1_000_000_007
for i in range(N):
    A[i]=list(map(int,input().split()))
dp=[[0 for _ in range(1<<N)] for _ in range(N+1)]
dp[0][0]=1
for i in range(N):
    for k in range(1<<N):
        if dp[i][k]==0: continue
        for j in range(N):
            if A[i][j]==0: continue
            if (k>>j)&1==1: continue
            dp[i+1][k|(1<<j)]+=dp[i][k]
            dp[i+1][k|(1<<j)]%=MOD
print(dp[N][(1<<N)-1])