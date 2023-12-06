n, q = map(int, input().split())
a = [0 for _ in range(n + 1)]
for _ in range(q):
    s, t = map(int, input().split())
    if s == 1:
        a[t] += 1
    elif s == 2:
        a[t] += 2
    else:
        if a[t] >= 2:
            print("Yes")
        else:
            print("No")