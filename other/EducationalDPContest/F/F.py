s=input()
t=input()
s_len=len(s)
t_len=len(t)
dp=[[0 for _ in range(t_len+1)] for _ in range(s_len+1)]
for i in range(s_len):
    for j in range(t_len):
        dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j],dp[i][j]+(s[i]==t[j]))
ans=[]
i,j=s_len,t_len
while i>0 and j>0:
    if dp[i][j]==dp[i-1][j]:
        i-=1
    elif dp[i][j]==dp[i][j-1]:
        j-=1
    else:
        i-=1
        j-=1
        ans.append(s[i])
print("".join(ans[::-1]))