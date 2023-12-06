N = int(input())
D = [[0] * N for _ in range(N)]
for i in range(N-1):
    weights = list(map(int, input().split()))
    for j, w in enumerate(weights):
        D[i][i+j+1] = w
        D[i+j+1][i] = w
dp = [-float('inf')] * (1 << N)
dp[0] = 0

for mask in range(1 << N):
    u = None
    for j in range(N):
        if mask & (1 << j):
            u = j
            break
    if u is None:
        continue

    for v in range(u+1, N):
        if mask & (1 << v):
            dp[mask] = max(dp[mask], dp[mask ^ (1 << u) ^ (1 << v)] + D[u][v])
# print(dp)
print(max(dp))
