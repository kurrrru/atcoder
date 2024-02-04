# 005 - Restricted Digits (★★★★★★★)

import math
MOD = 1000000007

n, b, k = map(int, input().split())
c = list(map(int, input().split()))

n_ = int(math.log2(n))

# ten[i] = pow(10, 1<<i, b)
ten = [10 for _ in range(n_+1)]
for i in range(1, n_+1):
    ten[i] = ten[i-1] * ten[i-1] % b

# dp[2**i]
a = [[0 for _ in range(b)] for _ in range(n_ + 1)]
for i in range(k):
    a[0][c[i] % b] += 1

for i in range(n_):
    for j in range(b):
        for l in range(b):
            a[i + 1][(j * ten[i] + l) % b] += a[i][j] * a[i][l]
            a[i + 1][(j * ten[i] + l) % b] %= MOD

ans = [[0 for _ in range(b)] for _ in range(n_ + 2)] 
ans[n_+1][0] = 1

for i in range(n_, -1, -1):
    bit = n & (1 << i)
    if bit == 0:
        for j in range(b):
            ans[i][j] = ans[i+1][j]
    else:
        for j in range(b):
            for l in range(b): 
                ans[i][(j * ten[i] + l) % b] += ans[i+1][j] * a[i][l]
                ans[i][(j * ten[i] + l) % b] %= MOD

print(ans[0][0] % MOD)
    
        