N,K,Q=map(int,input().split())
a=[0]*N
d1={}
d2={}
s=0

d1[0]=K
d2[0]=N-K

def remove(dic, a):
    if dic[a]>1:
        dic[a]-=1
    else:
        dic.pop(a)
def add(dic, a):
    if a in dic:
        dic[a]+=1
    else:
        dic[a]=1        

for i in range(Q):
    x,y=map(int,input().split())
    x-=1
    changeFrom=a[x]
    changeTo=y
    a[x]=y
    d1min=min(d1)
    d2max=max(d2)
    if changeFrom>=d1min and changeTo>=d2max:
        remove(d1,changeFrom)
        add(d1,changeTo)
        s=s-changeFrom+changeTo
    elif changeFrom>=d1min and changeTo<d2max:
        remove(d1,changeFrom)
        add(d2,changeTo)
        remove(d2,d2max)
        add(d1,d2max)
        s=s-changeFrom+d2max
    elif changeFrom<d1min and changeTo>d1min:
        remove(d2,changeFrom)
        add(d1,changeTo)
        remove(d1,d1min)
        add(d2,d1min)
        s=s-d1min+changeTo
    elif changeFrom<d1min and changeTo<=d1min:
        remove(d2,changeFrom)
        add(d2,changeTo)
    print(s)