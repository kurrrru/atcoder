N=int(input())
T=[0]*N
D=[0]*N
time_list=[]
for i in range(N):
    T[i],D[i]=map(int,input().split())
    time_list.append((T[i]+D[i],T[i],i))
time_list.sort()
next_print=0
print_cnt=0
dp=[[[0,0],[0,0]] for _ in range(N+1)]
for i in range(N):
    if dp[i][0][0]<=time_list[i][0] and dp[i+1][1][1]<=dp[i][0][1]:
        dp[i+1][1][0]=max(dp[i][0][0]+1,time_list[i][1]+1)
        dp[i+1][1][1]=dp[i][0][1]+1
    if dp[i][1][0]<=time_list[i][0] and dp[i+1][1][1]<=dp[i][1][1]:
        dp[i+1][1][0]=max(dp[i][1][0]+1,time_list[i][1]+1)
        dp[i+1][1][1]=dp[i][1][1]+1
    if dp[i][0][1]==dp[i][1][1]:
        dp[i+1][0][0]=min(dp[i][0][0],dp[i][1][0])
        dp[i+1][0][1]=dp[i][0][1]
    elif dp[i][0][1]<dp[i][1][1]:
        dp[i+1][0][0]=dp[i][1][0]
        dp[i+1][0][1]=dp[i][1][1]
    elif dp[i][0][1]>dp[i][1][1]:
        dp[i+1][0][0]=dp[i][0][0]
        dp[i+1][0][1]=dp[i][0][1]
print(max(dp[N][1][1],dp[N][0][1]))
# print(dp)