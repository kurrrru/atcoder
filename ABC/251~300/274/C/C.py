import math
n = int(input())
a = list(map(int,input().split()))
c = [0 for i in range(2 * n + 2)]
for i in range(1, n + 1):
    c[2 * i] = c[a[i - 1]] + 1
    c[2 * i + 1] = c[a[i - 1]] + 1
for i in range(1, len(c)):
    print(c[i])


