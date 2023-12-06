#ABC236 D
N=int(input())
affinity=[[-1]*(2*N+1) for _ in range(2*N+1)]
for i in range(1,N*2):
    affinity[i][i+1:]=list(map(int,input().split()))


used=[False]*(2*N+1)
pair=[-1]*16
ans=0

def perm(pos,n):
    global used,pair,ans
    if pos==n:
        f=0
        for i in range(N):
           f^=affinity[pair[2*i]][pair[2*i+1]]
        ans=max(ans,f) 
        return
    a=1
    while used[a]:a+=1
    pair[2*pos]=a
    used[a]=True
    for b in range(pair[2*pos]+1,2*N+1): 
        if used[b]: continue
        pair[2*pos+1]=b
        used[b]=True
        perm(pos+1,n)
        used[b]=False
    used[a]=False
    return
perm(0,N)
print(ans)