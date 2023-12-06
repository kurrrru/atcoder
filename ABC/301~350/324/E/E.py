N,T=input().split()
N=int(N)
L=[0]*N # T[:L[i]]
R=[0]*N
for i in range(N):
    S=input()
    index=0
    for j in range(len(S)):
        if index==len(T):
            break
        if T[index]==S[j]:
            index+=1
    L[i]=index
    index=len(T)-1
    for j in range(len(S)-1,-1,-1):
        if index==-1:
            break
        if T[index]==S[j]:
            index-=1
    R[i]=index+1
from collections import Counter
C1=Counter(L)
C2=Counter(R)
cnt=0
acc1=[0]*(len(T)+1)
acc1[len(T)]=C1[len(T)]
acc2=[0]*(len(T)+1)
acc2[0]=C2[0]
for i in range(1,len(T)+1):
    acc1[len(T)-i]=acc1[len(T)-i+1]+C1[len(T)-i]
    acc2[i]=acc2[i-1]+C2[i]
for i in range(len(T)+1):
    cnt+=C1[i]*acc2[i]
print(cnt)