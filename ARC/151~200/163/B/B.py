N,M=map(int,input().split())
A=list(map(int,input().split()))
B=sorted(A[2:])
m=1e20
for i in range(N-1-M):
    j=i+M-1
    if A[0]<=B[i]:
        a=0
    else:
        a=A[0]-B[i]
    if B[j]<=A[1]:
        b=0
    else:
        b=B[j]-A[1]
    m=min(m,a+b)
print(m)