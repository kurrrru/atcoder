a,b=sorted(map(int,input().split()))
    
def func(x):
    s=str(x)
    n=len(s)
    dp=[[0,0] for _ in range(n)]
    if int(s[0])==9:
        dp[0][0]=1
        dp[0][1]=1
    elif int(s[0])>=5:
        dp[0][1]=1
    elif int(s[0])==4:
        dp[0][0]=1
    for i in range(1,n):
        j=int(s[i])
        dp[i][0]=dp[i-1][0]|(j in [4,9])
        dp[i][1]=dp[i-1][1]*10+dp[i-1][0]*j+(int(s[:i])-sum(dp[i-1])+1)*2-(not ("4" in s[:i] or "9" in s[:i]))*(2-j//5)
    print(dp)
    return sum(dp[n-1])

print(func(b)-func(a-1))