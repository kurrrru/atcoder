n, m = map(int, input().split())
e = []

for i in range(m):
    a, b = map(int, input().split())
    e.append([a, b])

e.sort(key=lambda x: x[0] + 1 / x[1])


dp = [1 for _ in range(m)]

for i in range(1, m):
    if e[i][1] > e[i - 1][1]:
        dp[i] = dp[i - 1] + 1
    else:
        dp[i] = dp[i - 1]
            
print(dp[-1])
