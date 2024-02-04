n, m = map(int, input().split())
stack = []
e = [[] for _ in range(n)]
c = [0 for _ in range(n)]
c[0] = 0

for i in range(m):
    u, v = map(int, input().split())
    e[u - 1].append(v - 1)
    e[v - 1].append(u - 1)
 
 
# def dfs():
#     global c, stack
#     u = stack.pop()
#     for v in e[u]:
#         if c[v] == 0:
#             c[v] = - c[u]
#             stack.append(v)
#         elif c[v] == c[u]:
#             return 0 # おしまい
#     if len(stack) == 0:
#         return 1
#     return dfs()    

d = 0
for i in range(n):
    if c[i] != 0:
        continue
    stack.append(i)
    d += 1
    c[i] = d
    f = 1
    while True:
        u = stack.pop()
        for v in e[u]:
            if c[v] == 0:
                c[v] = - c[u]
                stack.append(v)
            elif c[v] == c[u]:
                f = 0

                break
        if len(stack) == 0:
            f = 1
            break
        if f == 0:
            break
    
    if f == 0:
        break

if f == 0:
    print(0)
else:
    # dがcの最大値
    g = [[0,0] for _ in range(d + 1)] # [-, +]
    for i in range(n):
        if c[i] > 0:
            g[c[i]][1] += 1
        else:
            g[c[i]][0] += 1
    total = 0
    mul = 0
    s = 0
    for i in range(1, d + 1):
        mul += s * (g[i][0] + g[i][1])
        total += (g[i][0] * g[i][1])
        s += g[i][0] + g[i][1]
        
    if d == 1:
        print(total - m)
    else:
        print(total + mul - m)
            

        
        