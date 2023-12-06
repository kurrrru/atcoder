N = int(input())
P = list(map(int,input().split()))
sum_P=sum(P)
dp=[False for _ in range(sum_P+1)]
dp[0]=True
for i in range(N):
    for j in range(sum_P,P[i]-1,-1):
        dp[j]|=dp[j-P[i]]
print(sum(dp))