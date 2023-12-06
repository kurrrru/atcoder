N,X=map(int,input().split())
T=list(map(int,input().split()))
dp=[0]*(X+1)
MOD=998244353
dp[0]=1
for i in range(X+1):
    if dp[i]==0:
        continue
    for j in range(N):
        if i+T[j]>X:
            continue
        dp[i+T[j]]+=(dp[i]*pow(N,-1,MOD))%MOD
ans=0
for i in range(max(0,X-T[0]+1),X+1):
    ans+=dp[i]*pow(N,-1,MOD)
    ans%=MOD
print(ans)