from math import gcd
n = int(input())
x = list(map(int, input().split()))

prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47] # 15

def gcd_check(a):
    for i in range(n):
        if gcd(x[i], a) == 1:
            return False
    return True

ans = float("inf")

for s in range(1<<15):
    a = 1
    for i in range(15):
        if s & (1 << i) > 0:
            a *= prime[i]  
    if gcd_check(a):
        ans = min(ans, a)

print(ans)