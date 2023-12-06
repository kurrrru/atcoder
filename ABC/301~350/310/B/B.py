N,M=map(int,input().split())
P=[0]*N
C=[0]*N
F=[[] for _ in range(N)]
for i in range(N):
    P[i],C[i],*F[i]=map(int,input().split())
    F[i].sort()

def superior(i,j):
    if P[i] < P[j]:
        i,j=j,i
    if C[i]>C[j]:
        return False
    t = 0
    for k in range(C[i]):
        while t<C[j] and F[i][k]>F[j][t]:
                t+=1
        if t==C[j]:
            return False
        if F[i][k]==F[j][t]:
            t+=1
        else:
            return False
        
    if P[i]>P[j] or C[i]<C[j]:
        return True
    return False

for i in range(N-1):
    for j in range(i+1,N):
        if superior(i,j):
            print("Yes")
            break
    else:
        continue
    break
else:
    print("No")
