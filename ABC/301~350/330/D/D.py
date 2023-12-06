N=int(input())
S=[list(input()) for _ in range(N)]
l=[0]*N
c=[0]*N
for i in range(N):
    for j in range(N):
        if S[i][j]=="o":
            l[i]+=1
            c[j]+=1
ans=0
for i in range(N):
    for j in range(N):
        if S[i][j]=="o":
            ans+=(l[i]-1)*(c[j]-1)
print(ans)