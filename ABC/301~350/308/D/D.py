H,W=map(int,input().split())
S=[""]*H
for i in range(H):
    S[i]=input()
visited=[[False]*W for _ in range(H)]

snuke="snuke"
stack=[]
if S[0][0]!="s":
    print("No")
else:
    i=0
    j=0
    n=0
    stack.append((i,j,n))
    while stack:
        i,j,n=stack.pop()
        if i == H-1 and j == W-1:
            print("Yes")
            break
        if i+1<H and S[i+1][j]==snuke[(n+1)%5]:
            if not visited[i+1][j]:
                stack.append((i+1,j,(n+1)%5))
                visited[i+1][j]=True
        if j+1<W and S[i][j+1]==snuke[(n+1)%5]:
            if not visited[i][j+1]:
                stack.append((i,j+1,(n+1)%5))
                visited[i][j+1]=True
        if i-1>=0 and S[i-1][j]==snuke[(n+1)%5]:
            if not visited[i-1][j]:
                stack.append((i-1,j,(n+1)%5))
                visited[i-1][j]=True
        if j-1>=0 and S[i][j-1]==snuke[(n+1)%5]:
            if not visited[i][j-1]:
                stack.append((i,j-1,(n+1)%5))
                visited[i][j-1]=True
    else:
        print("No")