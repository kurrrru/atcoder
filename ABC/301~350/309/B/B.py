N=int(input())
A=[[]]*N
for i in range(N):
    A[i]=list(input())
tmp1=A[0][N-1]
tmp2=A[N-1][0]
A[0][1:]=A[0][:N-1]
A[N-1][:N-1]=A[N-1][1:]
for i in range(N):
    if i<N-1:
        A[i][0]=A[i+1][0]
    if i<N-1:
        A[N-i-1][N-1]=A[N-i-2][N-1]
A[1][N-1]=tmp1
A[N-2][0]=tmp2
for i in range(N):
    print("".join(A[i]))