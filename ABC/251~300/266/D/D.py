n=int(input())
t=[0]*n
x=[0]*n
a=[0]*n
for i in range(n):
    t[i],x[i],a[i]=map(int,input().split())
s0=[0]*(t[n-1]+1)
s1=[0]*(t[n-1]+1)
s2=[0]*(t[n-1]+1)
s3=[0]*(t[n-1]+1)
s4=[0]*(t[n-1]+1)
j=0
for i in range(1,t[n-1]+1):
    s0[i]=max(s0[i-1],s1[i-1])
    s1[i]=max(s0[i-1],s1[i-1],s2[i-1])
    if i>=2:
        s2[i]=max(s1[i-1],s2[i-1],s3[i-1])
    if i>=3:
        s3[i]=max(s2[i-1],s3[i-1],s4[i-1])
    if i>=4:
        s4[i]=max(s3[i-1],s4[i-1])
    if i==t[j]:
        if x[j]==0:
            s0[i]+=a[j]
        elif x[j]==1:
            s1[i]+=a[j]
        elif x[j]==2 and i>=2:
            s2[i]+=a[j]
        elif x[j]==3 and i>=3:
            s3[i]+=a[j]
        elif x[j]==4 and i>=4:
            s4[i]+=a[j]
        j+=1

print(max(s0[t[n-1]],s1[t[n-1]],s2[t[n-1]],s3[t[n-1]],s4[t[n-1]]))
