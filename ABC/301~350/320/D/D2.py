class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.rank = [1] * n
        self.diff_weight = [[0,0] for _ in range(n)]
    
    def find(self, x):
        if self.parent[x] == -1: return x
        root = self.find(self.parent[x])
        self.diff_weight[x][0] += self.diff_weight[self.parent[x]][0]
        self.diff_weight[x][1] += self.diff_weight[self.parent[x]][1]
        self.parent[x] = root
        return self.parent[x]
    
    def unite(self, x, y, w):
        # weight(y) - weight(x) = w
        w[0]+=self.weight(x)[0]
        w[1]+=self.weight(x)[1]
        w[0]-=self.weight(y)[0]
        w[1]-=self.weight(y)[1]
        x = self.find(x)
        y = self.find(y)
        if x == y: return
        if self.rank[x] < self.rank[y]: 
            x, y = y, x
            w = [-w[0],-w[1]]
        if self.rank[x] == self.rank[y]: self.rank[x] += 1
        self.parent[y] = x
        self.diff_weight[y] = w
        
    def issame(self, x, y): 
        return self.find(x) == self.find(y)
    
    def weight(self,x):
        self.find(x)
        return self.diff_weight[x]        
    
    def diff(self,x,y):
        if self.issame(x,y):
            return [self.diff_weight[y][i]-self.diff_weight[x][i] for i in range(2)]
    
N,M=map(int,input().split())
uf=UnionFind(N)
for _ in range(M):
    A,B,X,Y=map(int,input().split())
    A-=1
    B-=1
    uf.unite(A,B,[X,Y])
for i in range(N):
    if uf.issame(0,i):
        p=uf.diff(0,i)
        print(p[0],p[1])
    else:
        print("undecidable")