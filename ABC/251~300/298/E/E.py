n, a1, b1, p, q = map(int, input().split())

# 残りマス
a = n - a1
b = n - b1

# i回でゴールする組み合わせ
c = [0 for _ in range(101)]
d = [0 for _ in range(101)]


m = [[0 for _ in range(a)] for _ in range(a+1)]
n = [[0 for _ in range(b)] for _ in range(b+1)]
m[0][0] = 1
n[0][0] = 1

for i in range(1, a+1):
    for j in range(a):
        for s in range(1, p+1):
            if j + s >= a:
                c[i] += m[i-1][j]
            else:
                m[i][j+s] += m[i-1][j]

for i in range(1, b+1):
    for j in range(b):
        for s in range(1, q+1):
            if j + s >= b:
                d[i] += n[i-1][j]
            else:
                n[i][j+s] += n[i-1][j] 

MOD = 998244353

e = [1 for _ in range(101)]
e[100] = pow(p, -100, MOD)
for i in range(99,-1,-1):
    e[i] = (e[i+1] * p)%MOD
f = [1 for _ in range(101)]
f[100] = pow(q, -100, MOD)
for i in range(99,-1,-1):
    f[i] = (f[i+1] * q)%MOD

ans = 0
for j in range(1, b+1):
    for i in range(1, min(j,a)+1):
        ans = (ans + c[i] * e[i] * d[j] * f[j]) % MOD

# print(m)
# print(c)
# print(n)
# print(d)
print(ans)
