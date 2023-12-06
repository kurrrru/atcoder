N,M=map(int,input().split())
dist=[[float("inf")]*N for _ in range(N)]
for _ in range(M):
    a,b,c=map(int,input().split())
    dist[a-1][b-1]=c


def FloydWarshall(dist):
    """
    dist...隣接2点間の距離を表した2次元リスト
    隣接していなければ距離はinf
    """
    ans=0
    N=len(dist)
    for i in range(N):
        dist[i][i]=0
    for k in range(N):
        for s in range(N):
            for t in range(N):
                dist[s][t]=min(dist[s][t],dist[s][k]+dist[k][t])
        for s in range(N):
            for t in range(N):
                if dist[s][t]!=float("inf"):
                    ans+=dist[s][t]
    return ans
print(FloydWarshall(dist))