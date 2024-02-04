from collections import defaultdict
N=int(input())
d=defaultdict(int)
for i in range(N):
    S,C=map(int,input().split())
    k=(-S & S)
    odd_factor=S//k
    d[odd_factor]+=C*k
ans=0
for s in d:
    ans+=d[s].bit_count()
print(ans)
        