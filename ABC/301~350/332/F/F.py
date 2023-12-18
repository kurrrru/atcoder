MOD=998244353
N,M=map(int,input().split())
A=list(map(int,input().split()))
# L=[0]*N
# R=[0]*N
# X=[0]*N
B=[1]*(N+1) # 最後に割る
D=[0]*(N+1)
C=[0]*N
for i in range(N):
    D[i+1]=A[i]-D[i]    
for i in range(M):
    L,R,X=map(int,input().split())
    L-=1
    R-=1
    if L<R:
        B[L+1]=B[L+1]*(R-L+1)*pow(R-L,-1,MOD)%MOD
        B[R+2]=B[R+2]*pow(R-L+1,-1,MOD)*(R-L)%MOD
        D[L+1]+=(R-L)*X
        D[L+1]%=MOD
        D[R+2]-=(R-L)*X
        D[R+2]%=MOD
    else:
        B[R+2]=
        B[L+1]=






E=[0]*N
