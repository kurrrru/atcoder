class UnionFind:
    def __init__(self, n):
        self.p = [-1] * n
        self.r = [1] * n
        self.size = [1] * n
        self.team = list(range(n))
    
    def find(self, x):
        if self.p[x] == -1:
            return x
        else:
            self.p[x] = self.find(self.p[x])
            return self.p[x]
    
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.r[x] > self.r[y]:
            x, y = y, x
        if self.r[x] == self.r[y]:
            self.r[y] += 1
        self.size[y]+=self.size[x]
        self.p[x] = y
        
MOD=998244353
N=int(input())

edge=[[] for _ in range(2*N)]
uf=UnionFind(N)

for i in range(N):
    p,q=map(int,input().split())
    p-=1
    q-=1
    ppre=uf.find(p)
    qpre=uf.find(q)
    
    probp=uf.size[ppre]*pow(uf.size[ppre]+uf.size[qpre],-1,MOD)%MOD
    probq=uf.size[qpre]*pow(uf.size[ppre]+uf.size[qpre],-1,MOD)%MOD
    
    edge[N+i].append((uf.team[ppre],probp))
    edge[N+i].append((uf.team[qpre],probq))

    uf.unite(p,q)
    uf.team[uf.find(p)]=N+i
    
ans=[0]*(2*N)
s=2*N-2
stack=[]
stack.append(s)
while stack:
    u=stack.pop()
    for v,w in edge[u]:
        ans[v]=(ans[u]+w)%MOD
        stack.append(v)
for i in range(N):
    ans[i]=str(ans[i])
print(" ".join(ans[:N]))