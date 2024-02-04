MOD=998244353
N,M=map(int,input().split())
C=list(map(int,input().split()))
ans=0
for i in range(M):
    ans+=N*pow(C[i],-1,MOD)
    ans%=MOD
print(ans)