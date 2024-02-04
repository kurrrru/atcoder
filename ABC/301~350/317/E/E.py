import queue
H,W=map(int,input().split())
A=[[0] for _ in range(H)]
dire=[(0,1),(1,0),(0,-1),(-1,0)]
person=">v<^"
ob=person+"#"

for i in range(H):
    A[i]=list(input())
for i in range(H):
    for j in range(W):
        if A[i][j] in person:
            di,dj=dire[person.index(A[i][j])]
            k=1
            while 0<=i+di*k<H and 0<=j+dj*k<W:
                if A[i+di*k][j+dj*k] in ob:
                    break
                A[i+di*k][j+dj*k]="!"
                k+=1
        elif A[i][j]=="S":
            s=(i,j)
        elif A[i][j]=="G":
            t=(i,j)
ob=ob+"!"
i,j=s
A[i][j]=0
Q=queue.Queue(4000000)
Q.put(s)
# import pprint
# pprint.pprint(A)
while not Q.empty():
    i,j=Q.get()
    if (i,j)==t:
        print(A[i][j])
        exit()
    for di,dj in dire:
        if 0<=i+di<H and 0<=j+dj<W and type(A[i+di][j+dj])==str and (A[i+di][j+dj] == "." or A[i+di][j+dj] =="G"):
            A[i+di][j+dj]=A[i][j]+1
            Q.put((i+di,j+dj))
    # print(i,j)
    # pprint.pprint(A)
print(-1)
