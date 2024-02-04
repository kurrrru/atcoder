MOD=998244353
import queue
def prim(edge):
    "edge[u][i]: uから出ているi番目の辺の行先と辺のコストのリスト"
    E=sum(map(len,edge))
    V=len(edge)
    que=queue.PriorityQueue(E)
    s=0 # 開始点
    ret=0 # 最小全域木のコストの総和
    used=[False]*V
    cnt=0 # 最小全域木に含めた頂点数
    for j in range(len(edge[s])):
        que.put((edge[s][j][1],edge[s][j][0]))
    used[s]=True
    cnt+=1
    while not que.empty():
        c,v=que.get()
        if used[v]: continue
        ret+=c
        ret%=MOD
        used[v]=True
        cnt+=1
        for j in range(len(edge[v])):
            if not used[edge[v][j][0]]:
                que.put((edge[v][j][1],edge[v][j][0]))
    if cnt<V:
        return -1
    return ret%MOD

N,K=map(int,input().split())
A=list(map(int,input().split()))
edge=[[] for _ in range(N)]
for i in range(N-1):
    for j in range(i+1,min(N,i+K+1)):
        edge[i].append([j,max(A[i],A[j])])
mst=prim(edge)
gam=[1]*(N+1)
for i in range(1,N+1):
    gam[i]=gam[i-1]*i%MOD
print(gam[K+1]*mst%MOD)

