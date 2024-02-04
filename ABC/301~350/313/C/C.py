N=int(input())
A=list(map(int,input().split()))

s=sum(A)
if s%N==0:
    m=s//N
    cnt=0
    for i in range(N):
        cnt+=abs(A[i]-m)
    print(cnt//2)
else:
    maxA=s//N+1
    maxAn=s%N
    minA=s//N
    minAn=N-maxAn
    cnt=0
    A.sort(reverse=True)
    for i in range(N):
        if i<maxAn:
            cnt+=abs(A[i]-maxA)
        else:
            cnt+=abs(A[i]-minA)
    print(cnt//2)