D=int(input())
N=input()
M=len(N)
MOD=int(1e9+7)
dp=[[[0 for _ in range(D)] for _ in range(2)] for _ in range(M)]

for i in range(10):
    if i>int(N[0]):
        break
    if i==int(N[0]):
        dp[0][0][i%D]+=1
    else:
        dp[0][1][i%D]+=1
for i in range(M-1):
    for j in range(D):
        for k in range(10):
            dp[i+1][1][(j+k)%D]+=dp[i][1][j]
            dp[i+1][1][(j+k)%D]%=MOD
            if k==int(N[i+1]):
                dp[i+1][0][(j+k)%D]+=dp[i][0][j]
            elif k<int(N[i+1]):
                dp[i+1][1][(j+k)%D]+=dp[i][0][j]
print((dp[M-1][1][0]+dp[M-1][0][0]-1)%MOD)