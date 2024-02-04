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

N,M=map(int,input().split())
edge=[[[],[]] for _ in range(N)]
for _ in range(M):
    a,b=map(lambda x:int(x)-1, input().split())
    edge[a][0].append(b)
    edge[b][1].append(a)
topo=topologicalSort(edge,True)
if len(topo)!=N:
    print(-1)
else:
    print(" ".join(map(lambda x: str(x+1), topo)))