n, m = map(int, input().split())
l = [[] for _ in range(n)]
for _ in range(m):
    s, t = map(int, input().split())
    l[s - 1].append(t)
    l[t - 1].append(s)
for i in range(n):
    l[i].sort()
    print(len(l[i]), " ".join(list(map(str, l[i]))))