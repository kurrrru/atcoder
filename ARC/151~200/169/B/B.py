N,S=map(int,input().split())
A=list(map(int,input().split()))

Cl=A[0]
Sl=[1]*N
for i in range(1,N):
    Cl+=A[i]
    if Cl>S:
        Cl=A[i]
        Sl[i]=Sl[i-1]+1
    else:
        Sl[i]=Sl[i-1]
Cr=A[N-1]
Sr=[1]*N
for i in range(N-2,-1,-1):
    Cr+=A[i]
    if Cr>S:
        Cr=A[i]
        Sr[i]=Sr[i+1]+1
    else:
        Sr[i]=Sr[i+1]
m=Sr[0]
ans=-m*N*(N-1)//2+N
for i in range(N-1):
    ans+=Sr[i]*(N-i-1)+Sl[N-i-1]*(N-i-1)
print(ans)        

print(Sr)
print(Sl)



5+4+2+2+1+2+2+2