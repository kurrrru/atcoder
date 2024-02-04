
N,M=map(int,input().split())
C=[[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    C[i]=list(map(int,input().split()))

def neighboring():
    neighbor=[set() for _ in range(M+1)]
    for i in range(N):
        for j in range(N):
            if i<N-1 and C[i][j]!=C[i+1][j]:
                neighbor[C[i][j]].add(C[i+1][j])
                neighbor[C[i+1][j]].add(C[i][j])
            if j<N-1 and C[i][j]!=C[i][j+1]:
                neighbor[C[i][j]].add(C[i][j+1])
                neighbor[C[i][j+1]].add(C[i][j])
    neighbor=list(map(list,neighbor))
    return neighbor
def output(d):
    for i in range(N):
        print(*d[i])

def process1():
    d=[C[i].copy() for i in range(N)]
    for i in range(N):
        for j in range(N):
            for di,dj in [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]:
                if 0<=i+di<N and 0<=j+dj<N and C[i+di][j+dj]!=C[i][j]:
                    break
            else:
                if i==0 or j==0 or i==N-1 or j==N-1:
                    d[i][j]=0
                else:
                    for di,dj in [(-1,0),(0,-1),(0,1),(1,0)]:
                        if 0<=i+di<N and 0<=j+dj<N and d[i+di][j+dj]==0:
                            d[i][j]=0
                            break
    for i in range(N):
        for j in range(N):
            ...
    
    return d
    
    


def main():
    neighbor=neighboring()
    d=process1()
    output(d)
    
if __name__=="__main__":
    main()