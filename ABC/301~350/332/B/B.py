# AC
K,G,M=map(int,input().split())
a=0
b=0
for i in range(K):
    if a==G:
        a=0
    elif b==0:
        b=M
    else:
        c=min(G-a,b)
        a+=c
        b-=c
print(a,b)