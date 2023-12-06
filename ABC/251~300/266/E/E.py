n=int(input())
ans=0
s=[0,6,11,15,18,20,21]
a=[0]*(n+1)
for i in range(1,n+1):
    a[i]=s[6-int(a[i-1])]/6+int(a[i-1])*a[i-1]/6
print(a[n])