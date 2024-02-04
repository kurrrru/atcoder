# AC
N=int(input())
edge=[[] for _ in range(N)]
# dim=[0]*N # 1:leaf
for i in range(N-1):
    u,v=map(lambda x:int(x)-1,input().split())
    edge[u].append(v)
    edge[v].append(u)
    # dim[u]+=1
    # dim[v]+=1
used = [False] * N
used[0] = True
cnt = [1] * len(edge[0])
for i in range(len(edge[0])):
    used[edge[0][i]]= True
    stack = [edge[0][i]]
    while stack:
        u = stack.pop()
        for v in edge[u]:
            if used[v]: continue
            used[v] = True
            cnt[i] += 1
            stack.append(v)
ans = N - max(cnt)
print(ans)