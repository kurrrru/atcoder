N,D=map(int,input().split())
d={2:0,3:0,5:0}
for k in d:
    while D%k==0:
        D//=k
        d[k]+=1
if D!=1:
    print(0)
    exit()
l=(d[2]+1)*(d[3]+1)*(d[5]+1)
dp=[[0 for _ in range(l)] for _ in range(N+1)]

def at(p,q,r):
    p=min(d[2],p)
    q=min(d[3],q)
    r=min(d[5],r)
    return p+(d[2]+1)*q+(d[2]+1)*(d[3]+1)*r
def c(i):
    p=i%(d[2]+1)
    i//=(d[2]+1)
    q=i%(d[3]+1)
    r=i//(d[3]+1)
    return (p,q,r)
dp[0][at(0,0,0)]=1
for i in range(N):
    for j in range(l):
        p,q,r=c(j)    
        dp[i+1][at(p,q,r)]+=dp[i][j]/6
        dp[i+1][at(p+1,q,r)]+=dp[i][j]/6
        dp[i+1][at(p,q+1,r)]+=dp[i][j]/6
        dp[i+1][at(p+2,q,r)]+=dp[i][j]/6
        dp[i+1][at(p,q,r+1)]+=dp[i][j]/6
        dp[i+1][at(p+1,q+1,r)]+=dp[i][j]/6
print(dp[N][at(d[2],d[3],d[5])])