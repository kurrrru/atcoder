#ABC271 E
N,M,K=map(int,input().split())
root=[[] for _ in range(M)]
for i in range(M):
    root[i]=list(map(int,input().split()))
    root[i][0]-=1
    root[i][1]-=1

E=list(map(lambda x:int(x)-1,input().split()))
d=[float("inf")]*N
d[0]=0
for i in range(K):
    d[root[E[i]][1]]=min(d[root[E[i]][1]],d[root[E[i]][0]]+root[E[i]][2])
if d[N-1]==float("inf"):
    print(-1)
else:
    print(d[N-1])