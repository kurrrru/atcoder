import bisect
N,K=map(int,input().split())
X=[0]*N
Y=[0]*N
for i in range(N):
    X[i],Y[i]=map(int,input().split())
X.sort()
Y.sort()
X1=[0]*(N//2)
X1a=[0]*(N//2)
Y1=[0]*(N//2)
Y1a=[0]*(N//2)
for i in range(N//2):
    if i<N//2-1 or N%2==1:
        X1[i]+=(X[i+1]-X[i])*(i+1)+(X[N-i-1]-X[N-i-2])*(i+1)
        Y1[i]+=(Y[i+1]-Y[i])*(i+1)+(Y[N-i-1]-Y[N-i-2])*(i+1)
    else:
        X1[i]+=(X[i+1]-X[i])*(i+1)
        Y1[i]+=(Y[i+1]-Y[i])*(i+1)
    if i==0:
        X1a[i]=X1[i]
        Y1a[i]=Y1[i]
    else:
        X1a[i]=X1[i]+X1a[i-1]
        Y1a[i]=Y1[i]+Y1a[i-1]
X2=[0]*(N//2+1)    
Y2=[0]*(N//2+1)    
X2[0]=X[-1]-X[0]
Y2[0]=Y[-1]-Y[0]
for i in range(1,N//2+1):
    X2[i]=X2[i-1]-X1[i-1]//i
    Y2[i]=Y2[i-1]-Y1[i-1]//i
X3=X2[::-1]
Y3=Y2[::-1]


L=0
R=max(X2[0],Y2[0])
while R-L>1:
    mid=(R+L)//2
    isOK=False
    xi=bisect.bisect_left(X3,mid)
    yj=bisect.bisect_left(Y3,mid)
    xi=N//2-xi
    yj=N//2-yj
    if xi<0:
        i=0
    else:
        i=(X2[xi]-mid)*(xi+1)
        if xi>0:
            i+=X1a[xi-1]
    if yj<0:
        j=0
    else:
        j=(Y2[yj]-mid)*(yj+1)
        if yj>0:
            j+=Y1a[yj-1]
    if i+j<=K:
        isOK=True
    
    
    if isOK: R=mid
    else: L=mid
    # print(L,R,mid,i,j,xi,yj)
print(R)