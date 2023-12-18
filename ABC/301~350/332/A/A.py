# AC
N,S,K=map(int,input().split())
P=[0]*N
Q=[0]*N
ans=0
for i in range(N):
    P[i],Q[i]=map(int,input().split())
    ans+=P[i]*Q[i]
if ans<S:
    ans+=K
print(ans)