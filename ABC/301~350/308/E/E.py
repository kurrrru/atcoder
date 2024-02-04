N=int(input())
A=list(map(int,input().split()))
S=input()

#[000,001,010,011,100,101,110,111]

dp=[[[0]*8 for i in range(4)] for i in range(N)]

if S[0]=="M":
    if A[0]==0:
        dp[0][1][1]=1
    elif A[0]==1:
        dp[0][1][2]=1
    else:
        dp[0][1][4]=1
dp[0][0][0]=1

MEX=" MEX"

for i in range(1,N):
    for j in range(4):
        for k in range(8):
            if j == 0:
                dp[i][j][0]=1
            elif j >= 1:
                dp[i][j][k]+=dp[i-1][j][k]
            if S[i]==MEX[j]:
                dp[i][j][k|(1<<A[i])]+=dp[i-1][j-1][k]
                
b=[0,1,0,2,0,1,0,3]
ans = 0
for i in range(8):
    ans += dp[N-1][3][i]*b[i]
print(ans)