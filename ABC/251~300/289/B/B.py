n, m = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))
b = [-1 for _ in range(n)]
i = 0
j = 0
l = -1
r = -1
ne = 1

while j < n:
    if i >= len(a) or j < a[i]:
        b[j] = ne
        ne += 1
        j += 1
    elif j == a[i]:
        l = a[i]
        while i + 1 < m and a[i] + 1 == a[i + 1]:
            i += 1
        r = a[i] + 1
        for k in range(r, l - 1, -1):
            b[k] = ne
            ne += 1
        j = r + 1
        i += 1
print(" ".join(map(str, b)))
