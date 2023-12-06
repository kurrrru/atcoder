H,W,N=map(int,input().split())
a=[0]*N
b=[0]*N
grid = [[1 for _ in range(W)] for _ in range(H)]
for i in range(N):
    a[i],b[i]=map(lambda x:int(x)-1,input().split())
    grid[a[i]][b[i]]=0
ans=0
for i in range(H):
    for j in range(W):
        if i==0 or j==0:
            ans+=grid[i][j]
            continue
        if grid[i-1][j]==0 or grid[i][j-1]==0 or grid[i-1][j-1]==0 or grid[i][j]==0:
            ans+=grid[i][j]
            continue
        grid[i][j]=min(grid[i-1][j],grid[i][j-1],grid[i-1][j-1])+1
        ans+=grid[i][j]
print(ans)