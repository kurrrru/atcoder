import numpy as np
n = int(input())

N = 1000000
a = [1 for _ in range(N)]
for i in range(1, N):
    a[i] = a[i//2] + a[i//3]

def naive_f(n):
    if n == 0:
        return 1
    elif n < N:
        return a[n]
    else:
        return naive_f(n//2) + naive_f(n//3)


print(naive_f(n))
