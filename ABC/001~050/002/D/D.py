N,M=map(int,input().split())
E=[[False for _ in range(N)] for _ in range(N)]
for _ in range(M):
    s,t=map(lambda x: int(x)-1,input().split())
    E[s][t]=True
    E[t][s]=True
ans=0
for g in range((1<<N)-1, -1,-1):
    for i in range(N):
        for j in range(N):
            if i==j:continue
            if g&(1<<i)!=0 and g&(1<<j)!=0:
                if E[i][j]==False:
                    break
        else:
            continue
        break
    else:
        ans=max(ans,bin(g).count("1"))
print(ans)