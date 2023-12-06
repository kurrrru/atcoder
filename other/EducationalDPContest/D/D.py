N,W=map(int,input().split())
w=[0]*N
v=[0]*N
for i in range(N):
    w[i],v[i]=map(int,input().split())
dp=[0 for _ in range(W+1)]
for i in range(N):
    for j in range(W-w[i],-1,-1):
        dp[j+w[i]]=max(dp[j+w[i]],dp[j]+v[i])
print(max(dp))