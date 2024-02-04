N,S,T=map(int,input().split())
S-=1
T-=1
edge=[[] for _ in range(N)]
for _ in range(N-1):
    u,v=map(lambda x:int(x)-1,input().split())
    edge[u].append(v)
    edge[v].append(u)

p=[[-1,-1] for _ in range(N)]
p[S]=[-1,0]
stack=[S]
while stack:
    u=stack.pop()
    for i in range(len(edge[u])):
        if p[edge[u][i]][1]>=0:
            continue
        p[edge[u][i]]=[u,p[u][1]+1]
        stack.append(edge[u][i])

path=[T]
u=T
while p[u][0]!=-1:
    u=p[u][0]
    path.append(u)
path=path[::-1]
inpath=[False]*N
for i in range(len(path)):
    inpath[path[i]]=True

stack=[S]
ans=[0]*N
ans[S]=1
while stack:
    u=stack.pop()
    for i in range(len(edge[u])):
        if edge[u][i]==p[u][0]:
            continue
        if inpath[edge[u][i]]:
            ans[edge[u][i]]=1
        else:
            ans[edge[u][i]]=ans[u]+1
        stack.append(edge[u][i])

for i in range(N):
    print(ans[i])            




