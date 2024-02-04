import bisect
n=int(input())
a=list(map(int, input().split()))
b=[0 for _ in range(n)] 
for i in range(1,n):
    if i%2==0:
        b[i]=b[i-1]+a[i]-a[i-1]
    else:
        b[i]=b[i-1]

def sleeptime(i, t):
    if i==0 or i==1:
        return 0
    if i%2==0:
        return b[i-1]+t-a[i-1]
    if i%2==1:
        return b[i-1]

q=int(input())
for _ in range(q):
    l,r=map(int, input().split())
    li=bisect.bisect_left(a,l)
    ri=bisect.bisect_left(a,r)
    print(sleeptime(ri,r)-sleeptime(li,l))
