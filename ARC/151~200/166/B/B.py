import math
N,a,b,c=map(int,input().split())
A=list(map(int,input().split()))
dp=[[float("inf") for _ in range(8)] for _ in range(N+1)]
dp[0][0]=0
ab=math.lcm(a,b)
bc=math.lcm(b,c)
ac=math.lcm(c,a)
abc=math.lcm(a,b,c)
def di(x,d):
    return (d-x%d)%d
for i in range(N):
    zero=(A[i]%a==0)*4+(A[i]%b==0)*2+(A[i]%c==0)
    min_anyway=min(di(A[i],a),di(A[i],b),di(A[i],c))
    # print(di(A[i],a),di(A[i],b),di(A[i],c))
    dp[i+1][zero]=0
    dp[i+1][0]=0
    dp[i+1][1]=min(dp[i+1][1],dp[i][0]+di(A[i],c),dp[i][1])
    dp[i+1][2]=min(dp[i+1][2],dp[i][0]+di(A[i],b),dp[i][2])
    dp[i+1][4]=min(dp[i+1][4],dp[i][0]+di(A[i],a),dp[i][4])
    dp[i+1][3]=min(dp[i+1][3],dp[i][0]+di(A[i],bc),dp[i][1]+di(A[i],b),dp[i][2]+di(A[i],c),dp[i][3])
    dp[i+1][5]=min(dp[i+1][5],dp[i][0]+di(A[i],ac),dp[i][1]+di(A[i],a),dp[i][4]+di(A[i],c),dp[i][5])
    dp[i+1][6]=min(dp[i+1][6],dp[i][0]+di(A[i],ab),dp[i][4]+di(A[i],b),dp[i][2]+di(A[i],a),dp[i][6])
    dp[i+1][7]=min(dp[i+1][7],dp[i][0]+di(A[i],abc),
                   dp[i][1]+di(A[i],ab),
                   dp[i][2]+di(A[i],ac),
                   dp[i][4]+di(A[i],bc),
                   dp[i][3]+di(A[i],a),
                   dp[i][5]+di(A[i],b),
                   dp[i][6]+di(A[i],c),               
                   dp[i][7])
print(dp[N][7] if dp[N][7]!=float("inf") else -1)
# print(dp)
# print(A)
# print(a,b,c)

