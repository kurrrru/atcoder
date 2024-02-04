N,K=map(int,input().split())
MOD=1000000007

kd=[]
kd2={}
for i in range(1,int(K**(1/2))+1):
    if K%i==0:
        kd.append(i)
        kd.append(K//i)
kd.sort()

for i in range(len(kd)):
    kd2[kd[i]]=[]
    for j in range(i):
        if kd[i]%kd[j]==0:
            kd2[kd[i]].append([kd[j],j])
a=[0]*len(kd)

for i in range(len(kd)-1,-1,-1):
    b=N//kd[i]
    a[i]+=b*(b+1)//2*kd[i]
    for d,j in kd2[kd[i]]:
        a[j]-=a[i]

ans=0
for i in range(len(kd)):
    ans+=a[i]*(K//kd[i])
    ans%=MOD
print(ans)