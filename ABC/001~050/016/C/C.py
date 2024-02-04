def FloydWarshall(dist):
    """
    dist...隣接2点間の距離を表した2次元リスト
    隣接していなければ距離はinf
    """
    N=len(dist)
    for i in range(N):
        dist[i][i]=0
    for k in range(N):
        for s in range(N):
            for t in range(N):
                dist[s][t]=min(dist[s][t],dist[s][k]+dist[k][t])
    return dist

N,M=map(int,input().split())
dist=[[float("inf") for _ in range(N)] for _ in range(N)]
for i in range(N):
    dist[i][i]=0
for i in range(M):
    a,b=map(int,input().split())
    a-=1
    b-=1
    dist[a][b]=1
    dist[b][a]=1
dist=FloydWarshall(dist)

for i in range(N):
    cnt=0
    for j in range(N):
        if dist[i][j]==2:
            cnt+=1
    print(cnt)