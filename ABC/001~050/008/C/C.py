N=int(input())
C=[0]*N
for i in range(N):
    C[i]=int(input())

d=[0]*N
for i in range(N):
    for j in range(N):
        if C[i]%C[j]==0:
            d[i]+=1

ans=0
for i in range(N):
    ans+=((d[i]+1)//2)/d[i]
print(ans)