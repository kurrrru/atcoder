N,M=map(int,input().split())
S=input()
C=list(map(int,input().split()))

Cl=[[] for _ in range(M)]
for i in range(N):
    Cl[C[i]-1].append(i)

Sl=[0]*N
for i in range(M):
    for j in range(len(Cl[i])):
        Sl[Cl[i][j]]=Cl[i][j-1]
ans=""
for i in range(N):
    ans=ans+S[Sl[i]]
print(ans)