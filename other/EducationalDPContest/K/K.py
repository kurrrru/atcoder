N,K=map(int,input().split())
A=list(map(int,input().split()))
dp=[0]*(K+1)
for i in range(A[0]):
    dp[i]=1
for i in range(K+1):
    for j in range(N):
        if i+A[j]>K:
            break
        if dp[i+A[j]]>=0:
            dp[i+A[j]]=dp[i]*(-1)
if dp[K]==1:
    print("Second")
elif dp[K]==-1:
    print("First")        