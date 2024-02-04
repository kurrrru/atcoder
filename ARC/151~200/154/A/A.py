MOD = 998244353

n = int(input())
a = list(input())
b = list(input())
a = list(map(int, a))
b = list(map(int, b))
f = 0
for i in range(n):
    if f == 0:
        if a[i] > b[i]:
            f = 1
        elif b[i] > a[i]:
            f = 1
            a[i], b[i] = b[i], a[i]
    elif f == 1:
        if a[i] < b[i]:
            a[i], b[i] = b[i], a[i]
A = 0
B = 0
for i in range(n):
    A = A * 10 + a[i]
    B = B * 10 + b[i]
print(A * B % MOD)