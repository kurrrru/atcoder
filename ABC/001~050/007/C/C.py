import queue
R,C=map(int,input().split())
sy,sx=map(int,input().split())
gy,gx=map(int,input().split())
maze=[""]*R
for i in range(R):
    maze[i]=list(input())
maze[sy-1][sx-1]=0
Q=queue.Queue(R*C)
Q.put((sy-1,sx-1))
while not Q.empty():
    i,j=Q.get()
    for di,dj in [(0,1),(0,-1),(1,0),(-1,0)]:
        if not (0<=i+di<R and 0<=j+dj<C):
            continue
        if i==gy-1 and j==gx-1:
            print(maze[i][j])
            break
        if maze[i+di][j+dj]==".":
            maze[i+di][j+dj]=maze[i][j]+1
            Q.put((i+di,j+dj))