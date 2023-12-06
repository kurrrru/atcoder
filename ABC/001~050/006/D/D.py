import bisect
N=int(input())
c=[0]*N
for i in range(N):
    c[i]=int(input())
dp=[float("inf")]*N
cnt=0
for i in range(N):
    l=bisect.bisect(dp,c[i])
    dp[l]=c[i]
    cnt=max(cnt,l+1)
print(N-cnt)
