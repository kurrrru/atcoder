n = int(input())
a = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, int(i ** (1/2)) + 1):
        if i % j == 0:
            a[i] += 2
            if j == i ** (1/2):
                a[i] -= 1
c = 0
for i in range(1, n):
    c += a[i] * a[n - i]
print(c)
