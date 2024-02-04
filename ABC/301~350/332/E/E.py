import numpy,bisect
N,D=map(int,input().split())
W=list(map(int,input().split()))
A=[-1]*N
ans=1e30
def f(i,d,g):
    global ans
    if i==N:
        X=[0]*D
        for i in range(N):
            X[A[i]]+=W[i]
        ans=numpy.var(X)
        return 
    if d==1:
        A[i]=g
        
        




print(ans)
