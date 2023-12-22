import bisect 
N = int(input())
A = list(map(int,input().split()))
A.sort()
Q = int(input())
for _ in range(Q):
    B = int(input())
    j = bisect.bisect(A, B)
    if j<=0:
        print(abs(A[0]-B))
    elif j>=N:
        print(abs(A[N-1]-B))
    else:
        print(min(abs(A[j]-B),abs(A[j-1]-B)))