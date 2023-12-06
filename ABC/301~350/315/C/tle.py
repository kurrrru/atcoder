N=int(input())
F=[0]*N
S=[0]*N
for i in range(N):
    F[i],S[i]=map(int,input().split())

m=0
for i in range(N-1):
    for j in range(i+1,N):
        if F[i]==F[j]:
            m=max(m,S[i]+S[j]-min(S[i],S[j])//2)
        else:
            m=max(m,S[i]+S[j])
print(m)
