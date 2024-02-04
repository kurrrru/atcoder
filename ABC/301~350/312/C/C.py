N,M=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
A.sort()
B.sort()
import bisect

ans=B[M-1]+1

for i in range(N):
    a=bisect.bisect(A,A[i])
    j=bisect.bisect_left(B,A[i])
    if a>=M-j:
        ans=min(ans,A[i]) 
for i in range(M):
    a=bisect.bisect(A,B[i]+1)
    j=bisect.bisect_left(B,B[i]+1)
    if a>=M-j:
        ans=min(ans,B[i]+1) 

print(ans)



