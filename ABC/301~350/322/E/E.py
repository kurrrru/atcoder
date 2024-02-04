N,K,P=map(int,input().split())
C=[0]*N
A=[[0]*K for _ in range(N)]
for i in range(N):
    C[i],*A[i]=map(int,input().split())
dp=[[float("inf") for _ in range(6**5)] for _ in range(N+1)]
dp[0][0]=0
indexlist=[]
def six_to(x):
    ret=[]
    while x>0:
        ret.append(x%6)
        x//=6
    return ret

for i in range(6**5):
    l=six_to(i)
    if len(l)<=K and (len(l)==0 or max(l)<=P):
        indexlist.append(i)
def add(i,j):
    l=six_to(j)
    l=l+[0]*(max(0,K-len(l)))
    for k in range(K):
        l[k]=min(P,l[k]+A[i][k])
    ret=0
    for k in range(K):
        ret=ret*6+l[K-k-1]
    return ret
        
    

for i in range(N):
    for j in indexlist:
        if dp[i][j]==float("inf"): continue
        dp[i+1][j]=min(dp[i+1][j],dp[i][j])
        k=add(i,j)
        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+C[i])
Pi=0
for i in range(K):
    Pi=Pi*6+P

if dp[N][Pi]==float("inf"):
    print(-1)
else:
    print(dp[N][Pi])
