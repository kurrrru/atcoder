N,T=input().split()
N=int(N)
M=len(T)
ans=[]
for i in range(N):
    S=input()
    for l in range(M+1):
        if l>=min(M,len(S)) or S[l]!=T[l]: break
    for r in range(M+1):
        if r>=min(M,len(S)) or S[-r-1]!=T[-r-1]: break
    if l==r==M==len(S) or l+r==M-1==len(S)-1 or (M==len(S)-1 and M<=l+r) or (M-1==len(S) and M-1<=l+r):
        ans.append(i+1)
print(len(ans))
print(*ans)