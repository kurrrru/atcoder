def topologicalSort(edge):
    N=len(edge)
    stack=[]
    ret=[]
    indegree=[0]*N
    for i in range(N):
        indegree[i]=len(edge[i][1])
        if indegree[i]==0:
            stack.append(i)
    while stack:
        v=stack.pop()
        ret.append(v)
        for i in range(len(edge[v][0])):
            indegree[edge[v][0][i]]-=1
            if indegree[edge[v][0][i]]==0:                
                stack.append(edge[v][0][i])
    return ret

N,M=map(int,input().split())
edge=[[[],[]] for _ in range(N)]
for _ in range(M):
    x,y=map(lambda x:int(x)-1,input().split())
    edge[x][0].append(y)
    edge[y][1].append(x)
order=topologicalSort(edge)
path_length=[0]*N
for i in range(N):
    v=order[i]
    for u in edge[v][1]:
        path_length[v]=max(path_length[v],path_length[u]+1)
print(max(path_length))