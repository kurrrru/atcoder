N=int(input())
d=[[[-1]*100 for _ in range(100)] for _ in range(100)]
for a in range(N):
    x1,y1,z1,x2,y2,z2=map(int,input().split())
    for i in range(x1,x2):
        for j in range(y1,y2):
            for k in range(z1,z2):
                d[i][j][k]=a

cnt=[]


def check(i,j,k,l,m,n):
    if l>=100 or m>=100 or n>=100:
        return False
    if d[i][j][k]!=-1 and d[l][m][n]!=-1 and d[i][j][k]!=d[l][m][n]:
        return True
    return False


for i in range(100):
    for j in range(100):
        for k in range(100):
            for di,dj,dk in [(1,0,0),(0,1,0),(0,0,1)]:
                if check(i,j,k,i+di,j+dj,k+dk):
                    cnt.append((d[i][j][k],d[i+di][j+dj][k+dk]))
cnt=set(cnt)
ans=[0]*N
for s,t in cnt:
    ans[s]+=1
    ans[t]+=1
                    
                    
for i in range(N):
    print(ans[i])