N=int(input())
A=list(map(int,input().split()))
A.sort()
for i in range(N):
    if A[i]!=A[0]+i:
        print(A[0]+i)
        break