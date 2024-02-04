import math
def area(r1,t1,r2,t2):
    x1=r1*math.cos(t1)
    y1=r1*math.sin(t1)
    x2=r2*math.cos(t2)
    y2=r2*math.sin(t2)
    return abs(x1*y2-x2*y1)/2

def areaall(R,T):
    N=len(R)
    ret=0
    for i in range(N-1):
        ret+=area(R[i],T[i],R[i+1],T[i+1])
    ret-=area(R[0],T[0],R[N-1],T[N-1])
    return ret

N=int(input())
R=list(map(int,input().split()))
D=[0]*N
m=max(R)
for i in range(N):
    if R[i]==m:
        D[i]=1



L=[]
for i in range(1,N-1):
    L.append((R[i],R[i-1]+R[i+1],i))
L.sort()
