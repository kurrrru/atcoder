import bisect
N,M,P=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
A.sort()
B.sort()
C=[0]*(M+1)
for i in range(M):
    C[i+1]=C[i]+B[i]

ans=0
for i in range(N):
    j=bisect.bisect(B,P-A[i])
    # print(j)
    # print(A[i]*j,C[j],(M-j)*P)
    ans+=A[i]*j+C[j]+(M-j)*P
print(ans)