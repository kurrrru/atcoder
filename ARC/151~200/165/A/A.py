import math
T=int(input())

def f(m):
    n=m
    ret=1
    for i in range(2,math.isqrt(n-1)+2):
        if i>n:
            break
        if n%i==0:
            k=1
            while n%i==0:
                n//=i
                k*=i
            ret+=k
    if n==m:
        ret=float("inf")
    return ret

for _ in range(T):
    N=int(input())
    if f(N)<=N:
        print("Yes")
    else:
        print("No")


