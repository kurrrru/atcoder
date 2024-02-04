X=10**6
import bisect
N,M,L=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[0]*L
d=[0]*L
e=[0]*L
for i in range(L):
    c[i],d[i]=map(lambda x:int(x)-1,input().split())
    e[i]=c[i]*X+d[i]
e.sort()
e.append(99999999999999)
  
Ls = L

a2=[a[i]*X+i for i in range(N)]
b2=[b[i]*X+i for i in range(M)]
a2.sort(reverse=True)
b2.sort(reverse=True)
if L==0:
    print(a2[0]//X+b2[0]//X)
    exit()
ans=0
for i in range(min(Ls,N)):
    for j in range(min(Ls,M)):
        x1,x2=divmod(a2[i],X)
        y1,y2=divmod(b2[j],X)
        if x1+y1<ans:
            break
        k=bisect.bisect_left(e,x2*X+y2)
        if e[k]==x2*X+y2:
            continue
        ans=x1+y1
print(ans)        
    
