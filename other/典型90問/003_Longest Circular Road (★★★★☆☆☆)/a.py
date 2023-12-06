# 003 - Longest Circular Road (★★★★☆☆☆)

# 木の直径を求める

n = int(input())
e = [[] for _ in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    e[a-1].append(b-1)
    e[b-1].append(a-1)

# sから1番遠い点uを探す
def farthest(s):
    stack = e[s].copy()
    d = [None for _ in range(n)]
    d[s] = 0
    for v in stack:
        d[v] = 1

    while stack:
        t = stack.pop()
        for v in e[t]:
            if d[v] == None:
                d[v] = d[t] + 1
                stack.append(v)
    return d.index(max(d)), max(d)


s = 0 # 適当にある点sを取る
u, _ = farthest(s) # sから1番遠い点uを求める
v, d = farthest(u) # uから1番遠い点vを求める

print(d+1)