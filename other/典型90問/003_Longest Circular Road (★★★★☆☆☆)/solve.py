N = int(input())
edge = [[] for _ in range(N)]
for _ in range(N - 1):
    u, v = map(lambda x:int(x)-1,input().split())
    edge[u].append(v)
    edge[v].append(u)
u = 0
v = 0
d = [-1] * N
d[u] = 0
stack = [u]
while stack:
    i = stack.pop()
    for j in edge[i]:
        if d[j] >= 0: continue    
        d[j] = d[i] + 1
        stack.append(j)
        if d[j] > d[v]:
            v = j
w = 0
d = [-1] * N
d[v] = 0
stack = [v]
while stack:
    i = stack.pop()
    for j in edge[i]:
        if d[j] >= 0: continue    
        d[j] = d[i] + 1
        stack.append(j)
        if d[j] > d[w]:
            w = j
print(d[w] + 1)
            