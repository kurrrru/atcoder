N,M=map(int,input().split())
A=list(map(int,input().split()))
A.sort(reverse=True)
ans=0
B=[0]*M
for i in range(M):
    B[i]+=A[i]
    if M+i<N:
        B[M-i-1]+=A[M+i]
for i in range(M):
    ans+=B[i]**2
    
print(ans)