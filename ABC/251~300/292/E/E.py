n, m = map(int, input().split())
d = [[] for _ in range(n)]
for _ in range(m):
    s, t = map(int, input().split())
    s, t = s - 1, t - 1
    d[s].append(t)
cnt = 0
for i in range(n):
    stack = []
    f = [False for _ in range(n)]
    f[i] = True
    for j in d[i]:
        stack.append((i, j))
    while stack:
        s, t = stack.pop()
        if f[t] == True:
            continue
        f[t] = True
        cnt += 1
        for e in d[t]:
            if f[e] == False:
                stack.append((t, e))
    cnt -= len(d[i])
print(cnt)