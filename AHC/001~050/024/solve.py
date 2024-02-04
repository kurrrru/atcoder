N,M=map(int,input().split())
C=[[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    C[i]=list(map(int,input().split()))

def output(d):
    for i in range(N):
        print(*d[i])


def check(D,i,j):
    firstfound=False
    e=[[-1 for _ in range(3)] for _ in range(3)]
    for di in range(3):
        for dj in range(3):
            if di==1 and dj==1:
                e[1][1]=0
                continue
            if not (0<=i+di-1<N and 0<=j+dj-1<N): 
                e[di][dj]=0
                continue
            if D[i+di-1][j+dj-1]==0:
                e[di][dj]=0
            elif not firstfound:
                e[di][dj]=1
                firstfound=True
            else:
                for (ddi,ddj) in [(0,1),(0,-1),(1,0),(-1,0)]:
                    if 0<=di+ddi<3 and 0<=dj+ddj<3 and e[di+ddi][dj+ddj]>0:
                        e[di][dj]=1
    for di in range(2,-1,-1):
        for dj in range(2,-1,-1):
            if di==1 and dj==1:
                e[1][1]=0
                continue
            if not (0<=i+di-1<N and 0<=j+dj-1<N): 
                e[di][dj]=0
                continue
            if D[i+di-1][j+dj-1]==0:
                e[di][dj]=0
            elif not firstfound:
                e[di][dj]=1
                firstfound=True
            else:
                for (ddi,ddj) in [(0,1),(0,-1),(1,0),(-1,0)]:
                    if 0<=di+ddi<3 and 0<=dj+ddj<3 and e[di+ddi][dj+ddj]>0:
                        e[di][dj]=1
    for di in range(3):
        for dj in range(3):
            if e[di][dj]==-1:
                return False

    if i==0 or i==N-1 or j==0 or j==N-1 or D[i+1][j]==0 or D[i-1][j]==0 or D[i][j+1]==0 or D[i][j-1]==0:    
        return True
    else:
        return False

def process1():
    d=[C[i].copy() for i in range(N)]
    for i in range(N):
        for j in range(N):
            for di,dj in [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]:
                if 0<=i+di<N and 0<=j+dj<N and C[i+di][j+dj]!=C[i][j]:
                    break
            else:
                if check(d,i,j):
                    d[i][j]=0
    for i in range(N-1,-1,-1):
        for j in range(N-1,-1,-1):
            for di,dj in [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]:
                if 0<=i+di<N and 0<=j+dj<N and C[i+di][j+dj]!=C[i][j]:
                    break
            else:
                if check(d,i,j):
                    d[i][j]=0
    return d

def main():
    d=process1()
    output(d)
    
if __name__=="__main__":
    main()