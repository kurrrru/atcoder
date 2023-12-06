x, y, z = map(int, input().split())
s = input()

dp = [[0,0] for _ in range(len(s))]

if s[0] == "A":
    dp[0][0] = y
    dp[0][1] = z + x
else:
    dp[0][0] = x
    dp[0][1] = z + y

for i in range(1, len(s)):
    if s[i] == "A":
        dp[i][0] = min(dp[i-1][0] + y, dp[i-1][1] + z + y)
        dp[i][1] = min(dp[i-1][0] + z + x, dp[i-1][1] + x)
    elif s[i] == "a":
        dp[i][0] = min(dp[i-1][0] + x, dp[i-1][1] + z + x)
        dp[i][1] = min(dp[i-1][0] + z + y, dp[i-1][1] + y)
print(min(dp[-1][0], dp[-1][1]))
