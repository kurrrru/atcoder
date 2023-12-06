import sys
sys.setrecursionlimit(1_000_000)
N=int(input())
A=list(map(int,input().split()))
dp=[[None for _ in range(N+1)] for _ in range(N)]
for i in range(N):
    dp[i][i+1]=A[i]
def f(s,t):
    global dp
    if dp[s][t]!=None:
        return dp[s][t]
    dp[s][t]=max(A[s]+f(s+1,t)*(-1),f(s,t-1)*(-1)+A[t-1])
    return dp[s][t]
print(f(0,N))