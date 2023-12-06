#いもす法
N=int(input())
M=1000001
C=[0]*M
for _ in range(N):
    a,b=map(int,input().split())
    C[a]+=1
    if b<M-1:
        C[b+1]-=1
popularity=[0]*M
popularity[0]=C[0]
for i in range(1,M):
    popularity[i]=popularity[i-1]+C[i]
print(max(popularity))