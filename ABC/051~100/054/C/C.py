N,M=map(int,input().split())
road=[[False for _ in range(N)] for _ in range(N)]
for _ in range(M):
    a,b=map(lambda x:int(x)-1,input().split())
    road[a][b]=True
    road[b][a]=True

used=[False]*N
perm=[-1]*N 
cnt=0

def operation():
    ret=True
    for i in range(1,N):
        ret&=road[perm[i-1]][perm[i]]
    ret &= (perm[0]==0)
    return ret

def permutation(pos, n):
    global perm, used, cnt
    # permの中に順列を生成する
    if pos == n:
        if operation():
            cnt+=1
        return cnt
    
    for i in range(n):
        if not used[i]:
            perm[pos] = i
            used[i] = True
            permutation(pos+1, n)
            used[i]=False
    return cnt

# 実行
permutation(0,N)
print(cnt)
