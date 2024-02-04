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

N,D=map(int,input().split())
P=[]
for i in range(N):
    x,y=map(int,input().split())
    P.append((x,y))

Q=UnionFind(N)

for i in range(N-1):
    for j in range(i+1,N):
        x1,y1=P[i]
        x2,y2=P[j]
        if (x1-x2)**2+(y1-y2)**2<=D**2:
            Q.unite(i,j)

s=Q.find(0)
for i in range(N):
    if Q.find(i)==s:
        print("Yes")
    else:
        print("No")

