from math import gcd, lcm
#n(n-1)//2 === mk + sum (mod n)
N,M=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
diff=0
for i in range(N):

    if A[i]!=i:
        break
else:
    print(0)
    exit()
s=sum(A)
goal=N*(N-1)//2
if gcd(N,M)!=1:
    if (goal-s)%gcd(N,M)!=0:
        print(-1)
        exit()
    else:
        g=gcd(N,M)
        s=0
        goal=(goal-s)//g
        N//=g
        M//=g
else:
    goal-=s

#n*x+m*y=sかつx<=0かつy>0のもとでmin(y)
def extgcd(a,b):
    if b==0: return (a,1,0)
    d,x,y=extgcd(b,a%b)
    return (d,y,x-(a//b)*y)
d,x,y=extgcd(N,M)
x*=goal
y*=goal
# X= x- mk k>= x/m
# Y= y+ nk k> -y/n
ans=y+N*max(x//M, (-y)//N+1) 
print(ans)