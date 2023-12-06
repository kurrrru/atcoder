T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    c = list(map(int, input().split()))
    u = [0 for _ in range(m)]
    v = [0 for _ in range(m)]
    for i in range(m):
        u[i], v[i] = map(int, input().split())
    if c[0] == c[n - 1]:
        print(-1)
        continue
    
    # その他の場合
    
    