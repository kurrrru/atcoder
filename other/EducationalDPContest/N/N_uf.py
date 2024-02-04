#WA
import queue
N=int(input())
A=list(map(int,input().split()))
que=queue.PriorityQueue(2*N)
for i in range(N-1):
    que.put((A[i]+A[i+1],i,i+1))

class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.rank = [1] * n
        self.weight = [A[i] for i in range(n)]
        self.max = [i for i in range(n)]
        self.min = [i for i in range(n)]
    
    def find(self, x):
        if self.parent[x] == -1: return x
        root = self.find(self.parent[x])
        self.parent[x] = root
        return self.parent[x]
    
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y: return
        if self.rank[x] < self.rank[y]: 
            x, y = y, x
        if self.rank[x] == self.rank[y]: self.rank[x] += 1
        self.weight[x] += self.weight[y]
        self.max[x] = max(self.right(x), self.right(y))
        self.min[x] = min(self.left(x), self.left(y))
        self.parent[y] = x
        
        
    def issame(self, x, y): 
        return self.find(x) == self.find(y)
    
    def right(self, x):
        return self.max[self.find(x)]
    def left(self, x):
        return self.min[self.find(x)]
    def size(self,x):
        return self.weight[self.find(x)]
    
uf=UnionFind(N)
ans=0
while not que.empty():
    w,s,t=que.get()
    if uf.issame(s,t):
        continue    
    if uf.size(s)+uf.size(t)!=w:
        continue
    ans+=w
    uf.unite(s,t)
    m1=uf.left(s)
    m2=uf.right(s)
    if m1>0:
        que.put((uf.size(m1)+uf.size(m1-1),m1,m1-1))
    if m2<N-1:
        que.put((uf.size(m2)+uf.size(m2+1),m2,m2+1))
print(ans)