S=input()
MOD=998244353
N=len(S)
dp=[[0]*(N) for _ in range(N)]
if N==1:
    print(0)
    exit()
    
if S[0]=="(" or S[0]=="?":
    dp[0][1]=1

for i in range(1,N):
    for j in range(N//2+1):
        if S[i]=="(":
            if j>0:
                dp[i][j]+=dp[i-1][j-1]
                dp[i][j]%=MOD
        elif S[i]==")":
            if j<N-1:
                dp[i][j]+=dp[i-1][j+1]
                dp[i][j]%=MOD
        else:
            if j>0:
                dp[i][j]+=dp[i-1][j-1]
            if j<N-1:
                dp[i][j]+=dp[i-1][j+1]
            dp[i][j]%=MOD
print(dp[N-1][0]%MOD)