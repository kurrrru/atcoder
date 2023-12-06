import bisect
N,M=map(int,input().split())
A=list(map(int,input().split()))
B=[[] for _ in range(N)]
P=[0]*N
for i in range(N):
    l=[]
    S=list(input())
    P[i]+=(i+1)
    for j in range(M):
        if S[j]=="o":
            P[i]+=A[j]
        else:
            l.append(A[j])
    l.sort(reverse=True)
    B[i]=[0]*(len(l)+1)
    for j in range(len(l)):
        B[i][j+1]=B[i][j]+l[j]

maxP=max(P)
for i in range(N):
    if maxP==P[i]:
        print(0)
        continue
    j=bisect.bisect_left(B[i],maxP-P[i])
    print(j)