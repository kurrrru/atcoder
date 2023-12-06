N=int(input())
D=[[] for _ in range(N)]
for i in range(N):
    D[i]=list(map(int,input().split()))

E=[[0 for _ in range(N)] for _ in range(N)]
E[0][0]=D[0][0]
for i in range(1,N):
    E[0][i]=E[0][i-1]+D[0][i]
    E[i][0]=E[i-1][0]+D[i][0]
for i in range(1,N):
    for j in range(1,N):
        E[i][j]=E[i-1][j]+E[i][j-1]-E[i-1][j-1]+D[i][j]

def calc(sx,sy,ex,ey):
    sx-=1
    sy-=1
    if sx<0 and sy<0:
        return E[ex][ey]
    if sx<0:
        return E[ex][ey]-E[ex][sy]
    if sy<0:
        return E[ex][ey]-E[sx][ey]
    return E[ex][ey]-E[sx][ey]-E[ex][sy]+E[sx][sy]
    
def div(n):
    ret=[]
    for d in range(1,n+1):
        if n%d==0:
            ret.append((d,n//d))
    return ret

def search(a,b):
    ret=0
    if a>N or b>N:
        return 0
    for i in range(N-a+1):
        for j in range(N-b+1):
            ret=max(ret,calc(i,j,i+a-1,j+b-1))
    return ret

F=[0 for _ in range(N**2+1)]
for i in range(1,N**2+1):
    divl=div(i)
    F[i]=F[i-1]
    for d1,d2 in divl:
        F[i]=max(F[i],search(d1,d2))

Q=int(input())
for _ in range(Q):
    P=int(input())
    print(F[P])