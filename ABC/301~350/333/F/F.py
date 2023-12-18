# AC
MOD=998244353
N = int(input())
dp = [[0]*(N+1) for _ in range(N+1)]
dp[2][0] = pow(3,-1, MOD)
dp[2][1] = pow(3,-1, MOD) * 2 % MOD
for i in range(3,N+1):
    for j in range(i-1):
        dp[i][0] += dp[i-1][j] * pow(2, -(i-j), MOD) % MOD
        dp[i][0] %= MOD
    dp[i][0] *= pow(2,i,MOD) * pow(pow(2,i,MOD)-1,-1,MOD) %MOD
    dp[i][0]%=MOD
    for j in range(1,i):
        dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) * pow(2,-1,MOD) %MOD
print(*dp[N][:N])
    