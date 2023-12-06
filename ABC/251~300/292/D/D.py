n, m = map(int, input().split())
d = [[] * n for _ in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    u, v = u - 1, v - 1
    d[u].append(v)
    d[v].append(u)
f = [False for _ in range(n)]

for i in range(n):
    if f[i] == False:
        stack = []
        enum = len(d[i])
        vnum = 1
        for e in d[i]:
            stack.append(e)
        f[i] = True
        while stack:
            t = stack.pop()
            if f[t] == True:
                continue
            f[t] = True
            vnum += 1
            enum += len(d[t])
            for e in d[t]:
                if f[e] == False:
                    stack.append(e)
        enum = enum // 2
        if enum != vnum:
            print("No")
            break
else:
    print("Yes")