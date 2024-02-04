def toTernary(N):
    t = []
    while N>0:
        t.append(N%3)
        N//=3
    return t

T=int(input())
for i in range(T):
    N,K=map(int,input().split())
    ter = toTernary(N)
    if N>=K>=sum(ter) and (K - sum(ter)) % 2 == 0:
        print("Yes")
    else:
        print("No")