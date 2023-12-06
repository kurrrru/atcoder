N=int(input())
X=[0]*N
Y=[0]*N
for i in range(N):
    X[i],Y[i]=map(int,input().split())
dist=[[pow(pow(X[i]-X[j],2)+pow(Y[i]-Y[j],2),1/2) for i in range(N)] for j in range(N)]

def dijkstra(s,dist,heap=True):
    """
    s...始点
    dist...隣接2点間の距離を表した2次元リスト
    隣接していなければ距離はinf
    heap...Trueなら、cをヒープとして扱う
    """
    N=len(dist) # 頂点数
    d=[float("inf")]*N
    S=[]
    c=[(float("inf"),i) for i in range(N)]
    c[s]=(0,s)
    used=[False]*N
    if heap:
        import heapq
        heapq.heapify(c)
    while len(S)<N:
        if heap:
            w,u=heapq.heappop(c)
            if used[u]:
                continue
        else:
            w,u=min(c)
        d[u]=w
        S.append(u)
        used[u]=True
        if not heap:
            c[u]=(float("inf"),u)
        for i in range(N):
            if not used[i]:
                if heap:
                    heapq.heappush(c,(d[u]+dist[u][i],i))
                else:
                    c[i]=min(c[i],(d[u]+dist[u][i],i))
    return d