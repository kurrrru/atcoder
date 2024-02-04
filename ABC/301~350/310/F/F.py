MOD=998244353
N=int(input())
A=list(map(int,input().split()))
Ainv=[pow(A[i],-1,MOD) for i in range(N)]
# bitDP
dp=[[0]*2048 for _ in range(N+1)]

dp[0][1]=1

for i in range(1,N+1):
    for j in range(1,min(A[i-1],10)+1):
        for k in range(2048):
            dp[i][k|(2047&(k<<j))]+=dp[i-1][k]*Ainv[i-1]
            dp[i][k|(2047&(k<<j))]%=MOD
    if A[i-1]>=11:
        for k in range(2048):
            dp[i][k]+=dp[i-1][k]*(A[i-1]-10)*Ainv[i-1]
            dp[i][k]%=MOD
ans=0
for i in range(1024,2048):
    ans+=dp[N][i]
    ans%=MOD
print(ans)