import heapq

N,Q=map(int,input().split())
A=list(map(int,input().split()))
M=200001
B=[0]*(M) # B[k] = (A[i]=kとなるiの個数)
for i in range(N):
    if A[i]<M:
        B[A[i]]+=1
C=[] # mexかもしれない数字の集合
for i in range(M):
    if B[i]==0:
        C.append(i)
mex=C[0]
for _ in range(Q):
    i,x=map(int,input().split())
    i-=1
    if A[i]<M: B[A[i]]-=1
    if x<M: B[x]+=1
    if A[i]<M and B[A[i]]==0:
        heapq.heappush(C,A[i])
    if B[mex]==0 and A[i]>=mex:
        print(mex)
        A[i]=x
        continue
    while B[C[0]]>0:
        heapq.heappop(C)
    mex=C[0]
    print(mex)
    A[i]=x