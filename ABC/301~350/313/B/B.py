N,M=map(int,input().split())

c=[0]*(N+1)
c[0]=1
for _ in range(M):
    _,B=map(int,input().split())
    c[B]=1
if sum(c)==N:
    print(c.index(0))
else:
    print(-1)