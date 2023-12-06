from operator import le


n=int(input())
p=list(map(int,input().split()))

def sortB(p):
    b=[]
    for i in range(len(p)):
        for j in range(len(p)-(2-(len(p)-i)%2),i,-2):
            if p[j]<p[i]:
                #iをメモ
                b.append(i)
                p[j],p[i]=p[i],p[j]
            # print(i,j)
    return b
def sortA(p):
    a=[]
    for i in range(len(p)-1):
        if (p[i]-i)%2==0:
            a.append(i)
            p[i],p[i+1]=p[i+1],p[i]
    return a
b1=sortB(p)
# print(p,b1)
a1=sortA(p)
# print(p,a1)
b2=sortB(p)
# print(p,b2)
cnt=len(b1)+len(a1)+len(b2)
print(cnt)
for i in range(len(b1)):
    print("B",b1[i]+1)
for i in range(len(a1)):
    print("A",a1[i]+1)
for i in range(len(b2)):
    print("B",b2[i]+1)
    
    