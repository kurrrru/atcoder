# AC
N=int(input())
A=list(map(int,input().split()))
P=list(map(lambda x:int(x)-1,input().split()))

edge=[[] for _ in range(N)]
for i in range(N-1):
    edge[P[i]].append(i+1)

# iからP_iに無向辺を引いて1からの距離x
# 1に、10^100 C x * A_iをたす
# 距離が遠い方が多く足す
# 最遠点の総和

d=[0]*N
stack=[0]
while stack:
    u=stack.pop()
    for v in edge[u]:
        d[v]=d[u]+1
        stack.append(v)
ans=[0]*N
for i in range(N):
    ans[d[i]]+=A[i]
for i in range(max(d),-1,-1):
    if ans[i]>0:
        print("+")
        break
    elif ans[i]<0:
        print("-")
        break
else:
    print(0)
        