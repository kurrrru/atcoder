N=int(input())
F=[0]*N
S=[0]*N
m=[0,-1]
for i in range(N):
    F[i],S[i]=map(int,input().split())
    if m[0]<S[i]:
        m=[S[i],i]
S[m[1]]=0

for i in range(N):
    if F[i]==F[m[1]]:
        S[i]//=2
print(m[0]+max(S))