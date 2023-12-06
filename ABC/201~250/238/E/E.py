N,Q=map(int,input().split())
class UnionFind():
    def __init__(self, n):
        self.p = [-1] * n
        self.r = [1] * n
    
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
        self.p[x] = y
uf=UnionFind(N+1)
for i in range(Q):
    l,r=map(int,input().split())
    uf.unite(l-1,r)
if uf.find(0)==uf.find(N):
    print("Yes")
else:
    print("No")
