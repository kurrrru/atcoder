N=int(input())
S=[[False for _ in range(100)] for _ in range(100)]
for _ in range(N):
    A,B,C,D=map(int,input().split())
    for i in range(A,B):
        for j in range(C,D):
            S[i][j]|=True

cnt=0
for i in range(100):
    for j in range(100):
        if S[i][j]:
            cnt+=1
print(cnt)