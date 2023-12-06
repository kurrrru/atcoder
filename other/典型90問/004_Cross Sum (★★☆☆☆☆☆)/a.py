# 004 - Cross Sum (★★☆☆☆☆☆)

h, w = map(int, input().split())
a = [[] for _ in range(h)]
for i in range(h):
    a[i] = list(map(int, input().split()))

c = [sum(a[i]) for i in range(h)]
d = [sum([a[j][i] for j in range(h)]) for i in range(w)]

b = [[c[i] + d[j] - a[i][j] for j in range(w)] for i in range(h)]

for i in range(h):
    print(" ".join(map(str, b[i])))