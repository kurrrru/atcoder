# O(nlogn)
n = int(input())
a = list(map(int, input().split()))
b = [0 for _ in range(n)]
for i in range(n-1,-1,-1):
    c = 0
    for j in range(1, n // (i + 1) + 1):
        c += b[(i + 1) * j - 1]
    if c % 2 != a[i]:
        b[i] = 1
c = []
for i in range(n):
    if b[i] == 1:
        c.append(str(i + 1))


if len(c) == 0:
    print(0)
else:
    print(len(c))
    print(" ".join(c))