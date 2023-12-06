n = int(input())
a = [0 for _ in range(n)]
b = [0 for _ in range(n)]
for i in range(n):
    a[i], b[i] = map(int, input().split())
MOD = 998244353 
x = [0 for _ in range(n)]
y = [0 for _ in range(n)]
x[0] = 1
y[0] = 1
for i in range(1, n):
    if a[i] == a[i - 1] and a[i] == b[i - 1]:
        x[i] = 0
    elif a[i] == a[i - 1]:
        x[i] = y[i - 1]
    elif a[i] == b[i - 1]:
        x[i] = x[i - 1]
    else:
        x[i] = (x[i - 1] + y[i - 1]) % MOD
    if b[i] == a[i - 1] and b[i] == b[i - 1]:
        y[i] = 0
    elif b[i] == a[i - 1]:
        y[i] = y[i - 1]
    elif b[i] == b[i - 1]:
        y[i] = x[i - 1]
    else:
        y[i] = (x[i - 1] + y[i - 1]) % MOD
print((x[-1] + y[-1]) % MOD)