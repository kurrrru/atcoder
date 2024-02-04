N,M=map(int,input().split())
A=[0]*M
B=[0]*M
C=[0]*M
dist=[[-float("inf") for _ in range(N)] for _ in range(N)]
edge=[[] for _ in range(N)]
for i in range(M):
    A[i],B[i],C[i]=map(lambda x: int(x)-1,input().split())
    C[i]+=1
    dist[A[i]][B[i]]=C[i]
    dist[B[i]][A[i]]=C[i]
    edge[A[i]].append(B[i])
    edge[B[i]].append(A[i])

ans=-float("inf")

used=[False]*N
def dfs(u,d):
    tmp=d
    global used,ans
    for v in edge[u]:
        if used[v]:
            continue
        d+=dist[u][v]
        ans=max(ans,d)
        used[v]=True
        dfs(v,d)
        used[v]=False
        d=tmp

for i in range(N):
    used[i]=True
    dfs(i,0)
    used[i]=False
print(ans)