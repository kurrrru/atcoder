n = int(input())
d = {}
a = [[] for _ in range(n)]
for i in range(n):
    m = int(input())
    for _ in range(m):
        p, e = map(int, input().split())
        a[i].append([p,e])
        if p not in d:
            d[p] = [e,i]
        else:
            if d[p][0] == e:
                d[p][1] = -1
            elif d[p][0] < e:
                d[p][0] = e
                d[p][1] = i
cnt = 0
f = 0
for i in range(n):
    for p,e in a[i]:
        if d[p][1] == i:
            cnt += 1
            break
    else:
        f = 1
print(cnt + f)            
                