N,M=map(int,input().split())
L=list(map(int,input().split()))
mL=max(L)


def check(m):
    if mL>m: return False
    now=0
    cnt=0
    for i in range(N):
        if now==0:
            now=L[i]
            cnt+=1
        elif now+L[i]+1<=m:
            now+=L[i]+1
        else:
            now=L[i]
            cnt+=1
    return cnt<=M  

l=0
r=sum(L)+N-1
while r-l>1:
    mid=(l+r)//2
    if check(mid):
        r=mid
    else:
        l=mid
print(r)
