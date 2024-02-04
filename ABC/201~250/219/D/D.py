#219-D
N=int(input())
X,Y=map(int,input().split())
a=[0]*N
b=[0]*N
for i in range(N):
    a[i],b[i]=map(int,input().split())
dp=[[[0]*(Y+1) for _ in range(X+1)] for _ in range(N+1)]
dp[0][0][0]=1
for i in range(N):
    for j in range(X+1):
        for k in range(Y+1):
            if dp[i][j][k]>0 and dp[i+1][j][k]>0:
                dp[i+1][j][k]=min(dp[i][j][k],dp[i+1][j][k])
            elif dp[i][j][k]>0:
                dp[i+1][j][k]=dp[i][j][k]
            if dp[i][j][k]>0:
                if dp[i+1][min(X,j+a[i])][min(Y,k+b[i])]>0:
                    dp[i+1][min(X,j+a[i])][min(Y,k+b[i])]=min(dp[i+1][min(X,j+a[i])][min(Y,k+b[i])],dp[i][j][k]+1)
                else:
                    dp[i+1][min(X,j+a[i])][min(Y,k+b[i])]=dp[i][j][k]+1
print(dp[N][X][Y]-1)                    
            
