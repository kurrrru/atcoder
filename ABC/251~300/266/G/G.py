import math
r,g,b,k=map(int,input().split())
MOD=998244353
n=r+g+b
fact=[1 for _ in range(n+1)]
invfact=[1 for _ in range(n+1)]
for i in range(1,n+1):
    fact[i]=fact[i-1]*i%MOD
# pow(fact,MOD-1)%MOD=1(フェルマーの小定理)
invfact[n]=pow(fact[n],MOD-2,MOD)
for i in range(n-1,0,-1):
    invfact[i]=invfact[i+1]*(i+1)%MOD
ans=fact[r+b]*fact[g+b]*invfact[k]*invfact[b]*invfact[r-k]*invfact[k+b]*invfact[g-k]%MOD
print(ans) 
