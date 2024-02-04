import sys
sys.setrecursionlimit(200050)

MOD=998244353
N=int(input())

edge=[[] for _ in range(2*N)]
team=[[i,1] for i in range(2*N)]

def find(p):
    if team[p][0]!=p:
        team[p]=find(team[p][0])
    return team[p]

for i in range(N-1):
    p,q=map(int,input().split())
    p-=1
    q-=1
    pteam=find(p)
    qteam=find(q)
    
    probp=pteam[1]*pow(pteam[1]+qteam[1],-1,MOD)%MOD
    probq=qteam[1]*pow(pteam[1]+qteam[1],-1,MOD)%MOD
    
    nextteam=N+i
    nextteamp=pteam[1]+qteam[1]
    
    edge[nextteam].append((pteam[0],probp))
    edge[nextteam].append((qteam[0],probq))
    
    team[p]=[nextteam,nextteamp]
    team[q]=[nextteam,nextteamp]
    team[pteam[0]]=[nextteam,nextteamp]
    team[qteam[0]]=[nextteam,nextteamp]
    team[nextteam]=[nextteam,nextteamp]
    
ans=[0]*(2*N)
s=2*N-2
stack=[]
stack.append(s)
while stack:
    u=stack.pop()
    for v,w in edge[u]:
        ans[v]=(ans[u]+w)%MOD
        stack.append(v)
for i in range(N):
    ans[i]=str(ans[i])
print(" ".join(ans[:N]))
