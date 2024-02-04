n=int(input())
tastiness=0
dp=[[0]*2 for _ in range(n)]
x,y=map(int,input().split())
if x==0:
    dp[0][0]=max(0,y)
else:
    dp[0][1]=y
for i in range(1,n):
    x,y=map(int,input().split())
    if x==0:
        dp[i][0]=max(max(dp[i-1][0],dp[i-1][1])+y,dp[i-1][0])
        dp[i][1]=dp[i-1][1]
    else:
        dp[i][0]=dp[i-1][0]
        dp[i][1]=max(dp[i-1][0]+y,dp[i-1][1])
print(max(dp[n-1]))