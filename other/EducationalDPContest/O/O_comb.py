N=int(input())
A=[[] for _ in range(N)]
MOD=1_000_000_007
for i in range(N):
    A[i]=list(map(int,input().split()))
dp=[[0 for _ in range(1<<N)] for _ in range(N+1)]
dp[0][0]=1

def nextset(x):
    smallest=x&-x
    ripple=x+smallest
    new_smallest=ripple&-ripple
    ones=((new_smallest//smallest)>>1)-1
    return ripple|ones

def gencomb(n,k):
    x=(1<<k)-1
    while x<(1<<n):
        
        x=nextset(x)

for i in range(1,N+1):
    x=(1<<i)-1
    while x<(1<<N):
        for j in range(N):
            if (x>>j)&1==1 and A[i-1][j]==1:
                dp[i][x]+=dp[i-1][x^(1<<j)]
                dp[i][x]%=MOD
        x=nextset(x)
print(dp[N][(1<<N)-1])