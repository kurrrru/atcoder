n, m = map(int, input().split())
a = list(map(lambda x: int(x) % m, input().split()))
a.sort()
l = []

tmp = 0
last = a[0]
for i in range(n):
    if not (a[i] == last or a[i] == last + 1):
        l.append(tmp)
        tmp = 0
    tmp += a[i]
    last = a[i]
l.append(tmp)

if a[0] == 0 and a[- 1] == m - 1 and len(l) >= 2:
    l[0] += l.pop()
print(sum(l) - max(l)) 