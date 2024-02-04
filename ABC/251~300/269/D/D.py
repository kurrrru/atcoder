#269-D
from collections import defaultdict
d=defaultdict(int)
    

N=int(input())
P=[0]*N
for i in range(N):
    P[i]=list(map(int,input().split()))
    d[(P[i][0],P[i][1])]=i+1

g=[0]*N
def dfs(u,gn):
    global g
    for di,dj in [(-1,-1),(-1,0),(0,-1),(0,1),(1,0),(1,1)]:
        if d[(P[u][0]+di,P[u][1]+dj)] and not g[d[(P[u][0]+di,P[u][1]+dj)]-1]:
            g[d[(P[u][0]+di,P[u][1]+dj)]-1]=gn
            dfs(d[(P[u][0]+di,P[u][1]+dj)]-1,gn)
gn=0
for i in range(N):
    if g[i]==0:
        gn+=1
        g[i]=gn
        dfs(i,gn)
print(gn) 