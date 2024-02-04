N,X=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
m=sum(A[1:N-2])
if m>=X:
    print(0)
elif m+A[N-2]<X:
    print(-1)
elif m+A[0]>=X:
    print(0)
else:
    print(min(A[N-2],X-m))
