n,m=map(int,input().split())
a=list(map(int,input().split()))
u=[0]*m
v=[0]*m
for i in range(m):
    u[i],v[i]=map(int,input().split())
    u[i]-=1
    v[i]-=1
    