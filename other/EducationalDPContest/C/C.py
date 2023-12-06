N=int(input())
a=[[0]*3 for _ in range(N)]
for i in range(N):
    a[i]=list(map(int,input().split()))
dp=[[0]*3 for _ in range(N+1)]
for i in range(N):
    for j in range(3):
        dp[i+1][j]=max(dp[i][(j+1)%3],dp[i][(j+2)%3])+a[i][j]
print(max(dp[N]))