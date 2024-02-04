from collections import defaultdict
N=int(input())
R=input()
C=input()
grid=[["."]*N for _ in range(N)]
if R[0]!=C[0]:
    print("No")
    exit()
Rd=defaultdict(int)
Cd=defaultdict(int)
Rn=[0]*N
Cn=[0]*N
for i in range(N):
    Rn[i]=Rd[R[i]]
    Cn[i]=Cd[C[i]]
    Rd[R[i]]+=1
    Cd[C[i]]+=1
for i in range(N):
    grid[i][Rn[i]]=R[i]
for i in range(N):
    if grid[Cn[i]][i] not in [".",C[i]]:
        print("No")
        exit()

R_set=[set() for _ in range(N)]
C_set=[set() for _ in range(N)]
for i in range(N):
    for j in range(N):
        if grid[i][j]==".":
            continue
        R_set[i].add(grid[i][j])
        C_set[j].add(grid[i][j])
if C_set[0]!={"A","B","C"}:
    print("No")
    exit()
    
        
