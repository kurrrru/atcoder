MOD=998244353
N=int(input())
S=input()
for i in range(N-1):
    if S[i]!="1" and S[i+1]!="1":
        print(-1)
        exit()
ans=1
for i in range(N-1,0,-1):
    ans+=(int(S[i])-1)*ans+1
    ans%=MOD
print((ans-1)%MOD)