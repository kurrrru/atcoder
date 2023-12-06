H,W=map(int,input().split())
d1=[{} for _ in range(H)]
d2=[{} for _ in range(W)]
a="qwertyuiopasdfghjklzxcvbnm"
for i in range(H):
    for j in a:
        d1[i][j]=0
for i in range(W):
    for j in a:
        d2[i][j]=0
c=["" for _ in range(H)]
for i in range(H):
    c[i]=list(input())
    for j in range(W):
        d1[i][c[i][j]]+=1
        d2[j][c[i][j]]+=1
ans=H*W

l1=[W]*H
l2=[H]*W
                


        

