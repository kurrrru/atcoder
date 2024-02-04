N,T,M=map(int,input().split())
bad = [[]]*N
for i in range(M):
    A,B=map(lambda x:int(x)-1,input().split())
    bad[A].append(B)
    bad[B].append(A)
    
