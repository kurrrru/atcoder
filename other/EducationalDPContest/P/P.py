import sys
sys.setrecursionlimit(1000000)
N=int(input())
edge=[[] for _ in range(N)]
MOD=1_000_000_007
for _ in range(N-1):
    x,y=map(lambda x:int(x)-1,input().split())
    edge[x].append(y)
    edge[y].append(x)
dp=[[0,0] for _ in range(N)]
visited=[False]*N
def f(i):
    if visited[i]:
        return dp[i]
    visited[i]=True
    dp[i]=[1,1]
    for u in edge[i]:
        if visited[u]: continue
        u_white,u_black=f(u)
        dp[i][0]*=u_white+u_black
        dp[i][0]%=MOD
        dp[i][1]*=u_white
        dp[i][1]%=MOD
    return dp[i]
print(sum(f(0))%MOD)