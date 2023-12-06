import heapq

N,M,K=map(int, input().split())
e={}
for _ in range(M):
    a,b=map(int,input().split())
    e[(a-1,b-1)]=1
    e[(b-1,a-1)]=1
for _ in range(K):
    p,h=map(int,input().split())
    e[(N,p-1)]=N+1-h
    e[(p-1,N)]=N+1-h

V = [i for i in range(N+1)]

def d(s,t):
    if s == t:
        return 0
    if (s,t) in e:
        return e[s,t]
    return float("inf")

def dijkstra(V,s):
    c=[0]*(len(V))
    for v in V:
        c[v]=d(s,v)
    U=[i for i in range(N)]
    Ui=[i for i in range(N)] 
       
    q=[]
    for i in range(N):
        if c[i] <= N+1:
            heapq.heappush(q,c[i]*N*3+i)
    l = N - 1
    while len(U)>0:
        if len(q) == 0:
            break
        a = heapq.heappop(q)
        h = a // (3*N)
        w = a % (3*N)
        while c[w]<h:
            a = heapq.heappop(q)
            h = a // (3*N)
            w = a % (3*N)        
        if h == float("inf"): break
        U[Ui[w]],U[l]=U[l],U[Ui[w]]
        Ui[U[Ui[w]]]=Ui[w]
        l-=1
        for i in range(l+1):
            v = U[i]
            if c[w]+d(w,v)<c[v]:
                c[v]=c[w]+d(w,v)
                if c[v] <= N+1:
                    heapq.heappush(q,c[v]*3*N+v)
    return c



c = dijkstra(V,N)
ans = []
for i in range(N):
    if c[i]<=N+1:
        ans.append(str(i+1))
print(len(ans))
print(" ".join(ans))

