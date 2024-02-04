N=int(input())
T=[0 for _ in range(289)]

def cut(s):
    a,b=s[0:2],int(s[2:4])
    b-=b%5
    b=str(b)
    b="0"*(2-len(b))+b
    return a+b

def cut2(s):
    a,b=int(s[0:2]),int(s[2:4])
    c=(5-b%5)%5
    b+=c
    if b>60:
        b-=60
        a+=1
    a=str(a)
    a="0"*(2-len(a))+a
    b=str(b)
    b="0"*(2-len(b))+b
    return a+b

def toTime(i):
    return "0"*(2-len(str(i//12)))+str(i//12)+"0"*(2-len(str(i%12*5)))+str(i%12*5)

def toi(s):
    return int(s[0:2])*12+int(s[2:4])//5

for _ in range(N):
    A=input()
    s=cut(A[0:4])
    e=cut2(A[5:9])
    for i in range(toi(s),toi(e)+1):
        if i==toi(s) and (T[i]==0 or T[i]==1):
            T[i]=1
        elif i==toi(e) and (T[i]==0 or T[i]==2):
            T[i]=2
        else:
            T[i]=3

for i in range(289):
    if T[i]==1:
        s=i
    elif T[i]==2:
        e=i
        print(toTime(s)+"-"+toTime(e))