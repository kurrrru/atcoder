N=int(input())
A=list(map(int,input().split()))

MOD=998244353
dp=[0]*(N)
dp[-1]=A[-1]
ac=[0]*N
ac[-1]=A[-1]

for i in range(N-2,-1,-1):
    dp[i]=A[i]+ac[i+1]*pow(N,-1,MOD)
    ac[i]=ac[i+1]+dp[i]
    dp[i]%=MOD
    ac[i]%=MOD
print(sum(dp)*pow(N,-1,MOD)%MOD)