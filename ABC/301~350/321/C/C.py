K=int(input())
ans=[]
def dfs(x):
    global ans
    for i in range(x%10-1,-1,-1):
        ans.append(x*10+i)
        dfs(x*10+i)
for i in range(10):
    dfs(i)
    ans.append(i)

ans.sort()
print(ans[K])