N=int(input())
D=[[0 for _ in range(N)] for _ in range(N)]
for i in range(N-1):
    D[i][i+1:]=list(map(int,input().split()))

w=0
ans=0
group=[0 for _ in range(N+1)]
def f(k,gn):
    global group,ans,w
    group[k]=gn    
    for i in range(k,N):
        if group[i]==0:
            group[i]=gn
            w+=D[k][i]
            ans=max(w,ans)
            for j in range(k,N):
                if group[j]==0:
                    f(j,gn+1)
            group[i]=0
            w-=D[k][i]
    group[k]=0

# print(D)
f(0,1)
f(1,1)
print(ans)
