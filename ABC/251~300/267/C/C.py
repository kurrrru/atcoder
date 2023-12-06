n,m=map(int,input().split())
a=list(map(int,input().split()))

#累積
c=[0]*n
c[0]=a[0]
for i in range(1,n):
    c[i]=c[i-1]+a[i]

#m個
d=[0]*(n-m+1)
d[0]=c[m-1]
for i in range(1,n-m+1):
    d[i]=c[i+m-1]-c[i-1]

e=0    
for i in range(m):
    e+=(i+1)*a[i]
me=e
for i in range(1,n-m+1):
    e=e-d[i-1]+m*a[i+m-1]
    if e>me:
        me=e
print(me)