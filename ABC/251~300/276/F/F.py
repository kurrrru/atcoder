"""
1 2 3

1...1/9
2...3/9
3...5/9

a[0] <= a[1] <= ... <= a[k-1]

P = sum(a[i] * (2*i + 1))
Q = k**2
"""

def xgcd(a, b):
    x0, y0, x1, y1 = 1, 0, 0, 1
    while b != 0:
        q, a, b = a // b, b, a % b
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return a, x0, y0

def modinv(a, m = 998244353):
    g, x, y = xgcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)


import bisect


# 任意の値の挿入をlognで行いたい
n = int(input())
a = list(map(int, input().split()))
b = []
sum = 0
for k in range(n):
    w = bisect.bisect(b, a[k])
    bisect.insort(b, a[k])
    sum += b[w] * (2 * w + 1)
    for i in range(w + 1,k + 1):
        sum += b[i] * 2
    ans = (sum * modinv((k + 1) ** 2)) % 998244353
    print(ans)
    