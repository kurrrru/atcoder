t = int(input())

def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)

for _ in range(t):
    n, d, k = map(int, input().split())
    m = gcd(n, d)
    a = (k-1) // (n//m)
    b = (k-1) % (n//m)
    print((d*b+a)%n)