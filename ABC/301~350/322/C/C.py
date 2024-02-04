import bisect
N,M=map(int,input().split())
A=list(map(int,input().split()))
for i in range(1,N+1):
    j=bisect.bisect_left(A,i)
    print(A[j]-i)