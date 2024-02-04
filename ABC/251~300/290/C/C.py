n, k = map(int, input().split())
a = list(set(map(int, input().split())))
a.sort()
i = 0
if a[0] != 0:
    print(0)
else:
    k -= 1
    while k > 0:
        if i + 1>= len(a):
            break
        if a[i] + 1 == a[i + 1]:
            i += 1
            k -= 1
        else:
            break
    print(i+1)
