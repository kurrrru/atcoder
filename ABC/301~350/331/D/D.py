N,Q=map(int,input().split())
P=[list(input()) for _ in range(N)]
acc=[[0]*N for _ in range(N)]
if P[0][0]=="B":
    acc[0][0]=1
for i in range(1,N):
    acc[i][0]=acc[i-1][0]+(P[i][0]=="B")
    acc[0][i]=acc[0][i-1]+(P[0][i]=="B")
    
for i in range(1,N):
    for j in range(1,N):
        acc[i][j]=acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1]+(P[i][j]=="B")


def f(x,y):
    if x<0 or y<0:
        return 0
    x1,x2 = divmod(x,N)
    y1,y2 = divmod(y,N)
    ret = acc[N-1][N-1]*x1*y1+acc[x2][N-1]*y1+acc[N-1][y2]*x1+acc[x2][y2]
    return ret


for _ in range(Q):
    a,b,c,d=map(int,input().split())
    ans = f(c,d) - f(a-1,d) - f(c,b-1) + f(a-1,b-1)
    print(ans)
    
    
    