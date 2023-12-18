N=int(input())
A=list(map(lambda x:int(x)-1,input().split()))
dp=[[0]*N for _ in range(N)]
if A[0]!=-2:
    dp[0][A[0]]=1
f=0
MOD=998244353
ans=1
for i in range(1,N):
    if A[i]!=-2:
        dp[i][A[i]]=dp[i-1][A[i]]+1
        if dp[i][A[i]]>=A[i]+2:
            f=1
            break
        continue
    cnt=0
    for j in range(N):
        if dp[i-1][j]==A[i]+1:
            continue
        cnt+=1
        dp[i][j]=dp[i-1][j]+1