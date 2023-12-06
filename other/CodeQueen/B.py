N=int(input())
M=[[True for _ in range(N)] for _ in range(N)]
for _ in range(N-1):
    x,y=map(int,input().split())
    M[x-1][y-1]=False
    x-=1
    y-=1
    for dx in [-1,0,1]:
        for dy in [-1,0,1]:
            if dx==0 and dy==0:
                continue
            k=1
            while 0<=x+dx*k<N and 0<=y+dy*k<N:
                M[x+dx*k][y+dy*k]=False
                k+=1
            

for i in range(N):
    for j in range(N):
        if M[i][j]:
            print(i+1,j+1)
            exit()
print(-1)