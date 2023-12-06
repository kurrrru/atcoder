from collections import Counter
N=int(input())
A=list(map(int,input().split()))
C=Counter(A)
dp=[[[0]*(N+1) for _ in range(N+1)] for _ in range(N+1)]
def f(a3,a2,a1,a0):
    if dp[a3][a2][a1]==0 and a0<N:
        if a3>0: dp[a3][a2][a1]+=f(a3-1,a2+1,a1,a0)*a3/(N-a0)
        if a2>0: dp[a3][a2][a1]+=f(a3,a2-1,a1+1,a0)*a2/(N-a0)
        if a1>0: dp[a3][a2][a1]+=f(a3,a2,a1-1,a0+1)*a1/(N-a0)
        dp[a3][a2][a1]+=N/(N-a0)
    return dp[a3][a2][a1]
print(f(C[3],C[2],C[1],C[0]))