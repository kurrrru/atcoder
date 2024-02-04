from math import gcd
N=int(input())
A=list(map(int,input().split()))
l=[0]*N
l[0]=A[0]
r=[0]*N
r[N-1]=A[N-1]
for i in range(1,N):
    l[i]=gcd(l[i-1],A[i])
    r[N-i-1]=gcd(r[N-i],A[N-i-1])
ans=max(l[N-2],r[1])
for i in range(1,N-1):
    ans=max(ans,gcd(l[i-1],r[i+1]))
print(ans)