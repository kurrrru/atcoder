N,L,R=map(int,input().split())
A=list(map(int,input().split()))
B=[0]*N
for i in range(N):
    if A[i]<L:
        B[i]=L
    elif L<=A[i]<=R:
        B[i]=A[i]
    else:
        B[i]=R
print(*B)