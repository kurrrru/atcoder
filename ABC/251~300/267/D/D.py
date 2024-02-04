n,m=map(int,input().split())
a=list(map(int,input().split()))

dp=[[-1e10]*m for _ in range(n)]
dp[0][0]=a[0]


for i in range(1,n):
    dp[i][0]=max(dp[i-1][0],a[i])
    for j in range(1,min(m,i+1)):
        if j>=i:
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+(j+1)*a[i])

print(dp[n-1][m-1])
