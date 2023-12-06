MOD=998244353
N=int(input())
A=list(map(int,input().split()))

d=1
for i in range(N):
    d=(d*pow(A[i],-1,MOD))%MOD

dp=[[0]*11 for _ in range(N)]
if A[0]>=10:
    for i in range(11):
        dp[0][i]=1
else:
    for i in range(A[0]+1):
        dp[0][i]=1

for i in range(1,N):
    for j in range(min(A[i],10)+1):
        for k in range(11):
            if k+j<=10:
                if j==0:
                    dp[i][k+j]+=dp[i-1][k]*A[i]
                else:
                    dp[i][k+j]+=dp[i-1][k]
                dp[i][k+j]%=MOD
print(dp)
print((dp[N-1][10]*d)%MOD)
