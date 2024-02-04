H,W=map(int,input().split())
a=["" for _ in range(H)]
for i in range(H):
    a[i]=input()
MOD=int(1e9+7)
dp=[[0 for _ in range(W+1)] for _ in range(H+1)]
dp[0][1]=1 # dp[1][1]=1としたいが、便宜上
for i in range(H):
    for j in range(W):
        if a[i][j]==".":
            dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]
            dp[i+1][j+1]%=MOD
        else:
            dp[i+1][j+1]=0
print(dp[H][W])