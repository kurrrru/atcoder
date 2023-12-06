s = input()
dp = [0 for _ in range(len(s)+1)]
d = {}
d[dp[0]] = 1
for i in range(len(s)):
    dp[i+1] = dp[i] ^ (1 << int(s[i]))
    if not dp[i+1] in d:
        d[dp[i+1]] = 1
    else:
        d[dp[i+1]] += 1
def f(n):
    return n*(n-1) // 2
cnt = 0
for v in d:
    cnt += f(d[v])
print(cnt)