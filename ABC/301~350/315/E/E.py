def topologicalSort(edge, minflag=False):
    """
    edge...list[list[list[int]]]
    edge[i][0] 頂点iから出る辺が入る頂点のリスト
    edge[i][1] 頂点iに入る辺が出る頂点のリスト
    
    minflag...bool 
    Trueなら、辞書順最小のトポロジカル順序を返す
    """
    if minflag:
        import heapq
        N=len(edge)
        heap=[]
        ret=[]
        indegree=[0]*N
        for i in range(N):
            indegree[i]=len(edge[i][1])
            if indegree[i]==0:
                heapq.heappush(heap,i)
        while heap:
            v=heapq.heappop(heap)
            ret.append(v)
            for i in range(len(edge[v][0])):
                indegree[edge[v][0][i]]-=1
                if indegree[edge[v][0][i]]==0:  
                    heapq.heappush(heap,edge[v][0][i])              
        return ret
    else:    
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

N=int(input())
P=[0]*N
C=[0]*N
for i in range(N):
    C[i],*P[i]=map(lambda x: int(x)-1,input().split())
    C[i]+=1
use=[False]*N
use[0]=True
stack=[0]
while stack:
    u=stack.pop()
    for i in range(C[u]):
        if use[P[u][i]]:    
            continue
        use[P[u][i]]=True
        stack.append(P[u][i])

edge=[[[],[]] for _ in range(N)]
for i in range(N):
    for j in range(C[i]):
        if use[P[i][j]] and use[i]:
            edge[i][1].append(P[i][j])
            edge[P[i][j]][0].append(i)
topo=topologicalSort(edge)
ans=[]

use[0]=False
for i in range(N):
    if use[topo[i]]:
        ans.append(str(topo[i]+1))
print(" ".join(ans))