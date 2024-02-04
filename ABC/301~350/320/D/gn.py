import random
N=random.randint(1,2e5)
M=random.randint(0,2e5)
print(N,M)

P=[[random.randint(-1e9,1e9),random.randint(-1e9,1e9)] for _ in range(N)]

for i in range(M):
    A=random.randint(1,N)
    B=random.randint(1,N)
    while A==B:
        A=random.randint(1,N)
        B=random.randint(1,N)
    print(A,B,P[B-1][0]-P[A-1][0],P[B-1][1]-P[A-1][1])