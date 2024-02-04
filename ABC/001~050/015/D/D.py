W=int(input())
N,K=map(int,input().split())
dp=[[0]*(W+1) for _ in range(K+1)]
for _ in range(N):
    A,B=map(int,input().split())
    for j in range(W,0,-1):
        if j<A:
            continue
        for i in range(K,0,-1):
            dp[i][j]=max(dp[i][j],dp[i-1][j-A]+B)
print(max(map(max,dp)))