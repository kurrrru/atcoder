A,B=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
dp=[[0 for _ in range(B+1)] for _ in range(A+1)]
for i in range(A):
    dp[i+1][0]=a[A-i-1]-dp[i][0]
for i in range(B):
    dp[0][i+1]=b[B-i-1]-dp[0][i]
for i in range(A):
    for j in range(B):
        dp[i+1][j+1]=max(a[A-i-1]-dp[i][j+1],b[B-j-1]-dp[i+1][j])
print((dp[A][B]+sum(a)+sum(b))//2)