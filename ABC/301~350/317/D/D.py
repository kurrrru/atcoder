N=int(input())
X=[0]*N
Y=[0]*N
Z=[0]*N
A=[0]*N
now=0
B=[]
C=[]
for i in range(N):
    X[i],Y[i],Z[i]=map(int,input().split())
    A[i]=max(0,(Y[i]-X[i]+1)//2)
    if A[i]==0:
        now+=Z[i]
    else:
        B.append(A[i])
        C.append(Z[i])
t=sum(Z)//2+1-now
# print(t)
# print(B)
# print(C)
if t<=0:
    print(0)
    exit()
#和がtを超えるようにCから選ぶとき、Bの和の最小値
M=len(B)
dp=[[float("inf") for _ in range(t+2)] for _ in range(M)]
#dp[i][j]: i番目までで和がjになるように選んだときのB[i]の最小値
dp[0][0]=0
if C[0]>t:
    dp[0][t+1]=B[0]
else:
    dp[0][C[0]]=B[0]

for i in range(M-1):
    for j in range(t+2):
        if j+C[i+1]>t:
            dp[i+1][t+1]=min(dp[i+1][t+1],dp[i][j]+B[i+1])
        else:
            dp[i+1][j+C[i+1]]=min(dp[i+1][j+C[i+1]],dp[i][j]+B[i+1])
        dp[i+1][j]=min(dp[i+1][j],dp[i][j])
print(min(dp[M-1][t],dp[M-1][t+1]))
# import pprint
# print(dp)