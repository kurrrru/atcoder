#ABC248 D
import bisect
N=int(input())
A=list(map(lambda x: int(x)-1,input().split()))

B=[[] for _ in range(N)]
for i in range(N):
    B[A[i]].append(i)

Q=int(input())
for _ in range(Q):
    L,R,X=map(lambda x: int(x)-1,input().split())
    Li=bisect.bisect(B[X],L-0.5)
    Ri=bisect.bisect(B[X],R+0.5)
    print(Ri-Li)