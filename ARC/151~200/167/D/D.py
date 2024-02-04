"""
e.g.
1 2 3 4 x

2 1 4 3


"""

class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.rank = [1] * n
        self.size = [1] * n
    
    def find(self, x):
        if self.parent[x] == -1: return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y: return
        if self.rank[x] > self.rank[y]: x, y = y, x
        if self.rank[x] == self.rank[y]: self.rank[y] += 1
        self.parent[x] = y
        self.size[y] +=self.size[x]
        
    def relative(self, x):
        return self.size[self.find(x)]
    
    def issame(self, x, y): 
        return self.find(x) == self.find(y)

def dfs(i,gn):
    group[i]=gn
    if group[P[i]-1]==-1:
        dfs(P[i]-1,gn)


T=int(input())
for _ in range(T):
    N=int(input())
    P=list(map(lambda x:int(x)-1,input().split()))
    gn=0
    group=[-1]*N
    uf=UnionFind(N)
    # print(P)
    for i in range(N):
        # print(N,i,P[i]-1)
        uf.unite(i,P[i])
        if group[i]==-1:
            dfs(i,gn)
            gn+=1
    M=0
    j=0
    Q=[-1]*N
    for i in range(N):
        Q[P[i]]=i
    gn-=1
    s=uf.relative(group.index(gn))
    X=uf.relative(0)
    for i in range(1,N):
        if uf.issame(i-1,i): continue
        r=P[i]
        flag=True
        for j in range(r):
            flag&=(P[j]<r)
        if r<P[i] or flag:
            a=r
        else:
            a=P[i] 
        P[i],P[Q[a]],Q[a],Q[P[i]]=P[Q[a]],P[i],i,Q[a]
        
        uf.unite(0,i)
        
    P=list(map(lambda x:x+1,P))
    print(*P)
            
        

            
        
"""
1と異なるグループで最小のものを1と交換
ただし、それによって

"""