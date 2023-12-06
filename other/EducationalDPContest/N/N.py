import sys
sys.setrecursionlimit(1<<31-1)
N=int(input())
A=list(map(int,input().split()))
acc=[0 for _ in range(N+1)]
for i in range(N):
    acc[i+1]=acc[i]+A[i]
dp=[[0 for _ in range(N+1)] for _ in range(N)]
def f(l,r):
    if dp[l][r]>0 or r==l+1:
        return dp[l][r]
    m=float("inf")
    for i in range(l+1,r):
        m=min(m,f(l,i)+f(i,r)+acc[r]-acc[l])
    dp[l][r]=m
    return m
print(f(0,N))