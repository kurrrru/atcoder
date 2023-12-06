def NAND(a,b):
    if a==1 and b==1:
        return 0
    return 1

N=int(input())
S=input()
dp=[[0,0] for _ in range(N)]

if S[0]=="0":
    dp[0][0]=1
else:
    dp[0][1]=1

ans=dp[0][1]
for i in range(1,N):
    if S[i]=="0":
        dp[i][0]=1
        dp[i][1]=dp[i-1][0]+dp[i-1][1]
    else:
        dp[i][0]=dp[i-1][1]
        dp[i][1]=1+dp[i-1][0]
    ans += dp[i][1]
print(ans)
