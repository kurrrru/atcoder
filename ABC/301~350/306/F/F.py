N,M=map(int,input().split())
A=[]
for i in range(N):
    A=A+list(map(lambda x: int(x)*1000+i,input().split()))
A.sort()
for i in range(N*M):
    A[i]%=1000
    
B=[A[i]*N*M+i for i in range(N*M)]
B.sort()
for i in range(N*M):
    B[i]%=(N*M)
    
    


dp=[[0 for _ in range(N)] for _ in range(N*M)]
for i in range(N):
    dp[0][i]=int(i<=A[0])

for i in range(1,N*M):
    for j in range(N):
        dp[i][j] = dp[i-1][j] + int(j<=A[i])    

ans = 0
for i in range(N*M):
    if A[i]==N-1: continue
    # print((N-A[i]-1)*dp[i][A[i]]-dp[i][A[i]+1],A[i],i)
    ans+=(N-A[i]-1)*dp[i][A[i]]-(N-A[i]-2)*dp[i][A[i]+1]

print(ans)
# print(A)
# print(dp)