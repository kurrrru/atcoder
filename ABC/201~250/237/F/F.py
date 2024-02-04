MOD=998244353
N,M=map(int,input().split())
dp=[[0 for _ in range(M**3)] for _ in range(N)]
for i in range(M):
    dp[0][i]=1
for i in range(1,N):
    for j in range(M**3):
        m0=j//M//M
        m1=j//M%M
        m2=j%M
        if (m1!=0 and m1<=m2) or (m0!=0 and m0<=m1): continue
        #m1>m2
        if m0==0 and m1==0:
            for k in range(M):
                if k<=m2:
                    dp[i][k]+=dp[i-1][j]
                    dp[i][k]%=MOD
                else:
                    dp[i][k*M+m2]+=dp[i-1][j]
                    dp[i][k*M+m2]%=MOD
        elif m0==0:
            for k in range(M):
                if k>m1:
                    dp[i][k*M**2+m1*M+m2]+=dp[i-1][j]
                    dp[i][k*M**2+m1*M+m2]%=MOD
                elif k>m2:
                    dp[i][k*M+m2]+=dp[i-1][j]
                    dp[i][k*M+m2]%=MOD
                else:
                    dp[i][m1*M+k]+=dp[i-1][j]
                    dp[i][m1*M+k]%=MOD
        else:
            for k in range(M):
                if k>m0:
                    break
                if k>m1:
                    dp[i][k*M**2+m1*M+m2]+=dp[i-1][j]
                    dp[i][k*M**2+m1*M+m2]%=MOD
                elif k>m2:
                    dp[i][m0*M**2+k*M+m2]+=dp[i-1][j]
                    dp[i][m0*M**2+k*M+m2]%=MOD
                else:
                    dp[i][m0*M**2+m1*M+k]+=dp[i-1][j]
                    dp[i][m0*M**2+m1*M+k]%=MOD
    # print(dp)
print(sum(dp[i][M**2:])%MOD)