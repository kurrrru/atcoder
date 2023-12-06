N,M=map(int,input().split())
K=1000000001
edge=[[] for _ in range(N)]
for _ in range(M):
    A,B,X,Y=map(int,input().split())
    A-=1
    B-=1
    edge[A].append([B,X,Y])
    edge[B].append([A,-X,-Y])
p=["undecidable" for _ in range(N)]
p[0]=[0,0]
stack=[0]
while stack:
    s=stack.pop()
    for i in range(len(edge[s])):
        t,x,y=edge[s][i]
        if p[t]=="undecidable":
            p[t]=[p[s][0]+x,p[s][1]+y]
            stack.append(t)
for i in range(N):
    if p[i]=="undecidable":
        print("undecidable")
    else:
        print(p[i][0],p[i][1])