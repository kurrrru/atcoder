N,D=map(int,input().split())
S=[input() for _ in range(N)]
tmp=0
ans=0
for d in range(D):
    for i in range(N):
        if S[i][d]=="x":
            tmp=0
            break
    else:
        tmp+=1
        ans=max(ans,tmp)
print(ans)