dp=[0]*1000001
dp[2]=1
for i in range(3,1000001):
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
    dp[i]%=10007

n=int(input())
print(dp[n-1])