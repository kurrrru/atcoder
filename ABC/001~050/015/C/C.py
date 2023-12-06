N,K=map(int,input().split())
T=[[0]*K for _ in range(N)]
for i in range(N):
    T[i]=list(map(int,input().split()))
for choice in range(K**N):
    i=0
    res=0
    while i<N:
        choice,r=divmod(choice,K)
        res^=T[i][r]
        i+=1
    if res==0:
        print("Found")
        exit()
print("Nothing")