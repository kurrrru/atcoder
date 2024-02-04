N,D,P=map(int,input().split())
F=list(map(int,input().split()))
F.sort(reverse=True)

s=0
for i in range(N//D+2):
    t=sum(F[i*D:(i+1)*D])
    s+=min(P,t)
print(s)