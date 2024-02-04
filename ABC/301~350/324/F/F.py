N,M=map(int,input().split())
edge=[[] for _ in range(N)]
for _ in range(M):
    u,v,b,c=map(int,input().split())
    edge[u-1].append((v-1,b,c))
dp=[[0,1,0] for _ in range(N)]
dp[0][1]=0
visited=[False]*N
visited[0]=True
for u in range(N):
    if not visited[u]: continue
    now_b=dp[u][0]
    now_c=dp[u][1]
    for v,b,c in edge[u]:
        if (now_b+b)*dp[v][1]>(now_c+c)*dp[v][0]:
            dp[v][0]=now_b+b
            dp[v][1]=now_c+c
            dp[v][2]=dp[v][0]/dp[v][1]
        visited[v]=True
    print(dp)
print(dp[N-1][2])