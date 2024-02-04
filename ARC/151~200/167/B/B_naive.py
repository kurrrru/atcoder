import math
def divisor_s(n):
    cnt=0
    for i in range(1,n+1):
        if n%i==0:
            cnt+=1
    return cnt

MOD=998244353
A,B=map(int,input().split())
print(divisor_s(A**B)*B//2%MOD)