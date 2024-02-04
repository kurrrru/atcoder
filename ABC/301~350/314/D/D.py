N=int(input())
S=list(input())
Q=int(input())

f=-1 #0:lower,1:upper
last=-1 #
lastupdate=[-1]*N
for i in range(Q):
    t,x,c=input().split()
    if t=="1":
        x=int(x)
        S[x-1]=c
        lastupdate[x-1]=i
    elif t=="2":
        f=0
        last=i
    else:
        f=1
        last=i
for i in range(N):
    if last>lastupdate[i]:
        if f==0:
            S[i]=S[i].lower()
        elif f==1:
            S[i]=S[i].upper()
print("".join(S))