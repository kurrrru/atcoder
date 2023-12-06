Q,K=map(int,input().split())
l=[]
for _ in range(Q):
    op,x=input().split()
    x=int(x)
    if op=="+":
        l.append(x)
    else:
        l.remove(x)
    n=len(l)
    dp=[[0 for _ in range(K+1)] for _ in range(n+1)]
    dp[0][0]=1
    for i in range(n):
        for j in range(K+1):
            dp[i+1][j]+=dp[i][j]
            if j+l[i]<=K:
                dp[i+1][j+l[i]]+=dp[i][j]
    print(dp[n-1][K])
    