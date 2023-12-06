n, m = map(int, input().split())
good = [range(i+1,n+1) for i in range(1, n+1)]
for _ in range(m):
    a = list(map(int, input().split()))
    for i in range(n-1):
        s,t = a[i], a[i+1]
        if s > t: s, t = t, s
        try:
            good[s-1].remove(t)
        except:
            pass
print(sum([len(good[i]) for i in range(n)]))