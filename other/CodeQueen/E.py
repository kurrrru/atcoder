N=int(input())
A=list(map(int,input().split()))

ans=0
maxB=-float("inf")
minB=float("inf")

for i in range(N):
    maxB=max(maxB,A[i])
    minB=min(minB,A[i])
    if i<N-2 and maxB-minB>max(maxB-A[i+1],A[i+1]-minB):
        ans+=maxB-minB
        maxB=-float("inf")
        minB=float("inf")
    elif i==N-1:
        ans+=maxB-minB    
print(ans)