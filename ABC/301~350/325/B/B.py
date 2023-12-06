N=int(input())
W=[0]*N
X=[0]*N


num=[0]*48
for i in range(N):
    W[i],X[i]=map(int,input().split())
    num[X[i]+9]+=W[i]
    num[X[i]+18]-=W[i]
ans=[0]*48
ans[0]=num[0]
for i in range(1,48):
    ans[i]=ans[i-1]+num[i]
for i in range(24):
    ans[i]+=ans[i+24]
print(max(ans[0:24]))

