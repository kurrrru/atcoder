import bisect
N=int(input())
A=list(map(int,input().split()))
B=sorted(list(set(A)))
C=[len(B)-bisect.bisect_left(B,A[i])-1 for i in range(N)]
A.sort(reverse=True)
D=[0 for _ in range(len(B))]
j=0

for i in range(1,len(B)):
    t=j
    D[i]=D[i-1]
    while A[j]==A[t]:
        D[i]+=A[j]
        j+=1

ans=[D[C[i]] for i in range(N)]
print(*ans)
    
    
    
