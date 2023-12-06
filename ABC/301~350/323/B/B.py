N=int(input())
S=[0]*N
for i in range(N):
    S[i]=input().count("o")*N+N-i-1
S.sort(reverse=True)
print(*map(lambda x:N-x%N,S))
