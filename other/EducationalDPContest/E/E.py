N,W=map(int,input().split())
w=[0]*N
v=[0]*N
for i in range(N):
    w[i],v[i]=map(int,input().split())
sum_v=sum(v)
dp=[W+1 for _ in range(sum_v+1)]
dp[0]=0
for i in range(N):
    for j in range(sum_v-v[i],-1,-1):
        dp[j+v[i]]=min(dp[j+v[i]],dp[j]+w[i])
for i in range(sum_v,-1,-1):
    if dp[i]<=W:
        print(i)
        break