n = int(input())
a = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, n // i + 1):
        a[i * j] += 1
c = 0
for i in range(1, n):
    c += a[i] * a[n - i]
print(c)
