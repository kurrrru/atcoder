from collections import Counter
N=int(input())
def f(x):
    for i in range(int(x**(1/2))+1,0,-1):
        if x%(i**2)==0:
            return x//(i**2)
        



L=[f(i) for i in range(1,N+1)]
C=Counter(L)
ans=0
for k in C:
    ans+=C[k]**2
print(ans)