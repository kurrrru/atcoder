# 008 - AtCounter (★★★★☆☆☆)

n = int(input())
s = input()

MOD = 1000000007
dp = [[0] * 7 for _ in range(n)]
if s[0] == "a":
    dp[0][0] = 1

# ここの部分、t="atcoder"として、s[i]==t[j]とすると簡潔にできる
for i in range(1, n):
    for j in range(7):
        dp[i][j] = dp[i-1][j]
    if s[i] == "a":
        dp[i][0] += 1
    elif s[i] == "t":
        dp[i][1] += dp[i-1][0]
        dp[i][1] %= MOD
    elif s[i] == "c":
        dp[i][2] += dp[i-1][1]
        dp[i][2] %= MOD
    elif s[i] == "o":
        dp[i][3] += dp[i-1][2]
        dp[i][3] %= MOD
    elif s[i] == "d":
        dp[i][4] += dp[i-1][3]
        dp[i][4] %= MOD
    elif s[i] == "e":
        dp[i][5] += dp[i-1][4]
        dp[i][5] %= MOD
    elif s[i] == "r":
        dp[i][6] += dp[i-1][5]
        dp[i][6] %= MOD

print(dp[n-1][6])