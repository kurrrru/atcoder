N=int(input())
S=[""]*N
for i in range(N):
    S[i]=input()
    S[i]=min(S[i],S[i][-1::-1])
print(len(set(S)))