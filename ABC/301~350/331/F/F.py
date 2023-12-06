N,Q=map(int,input().split())
S=list(input())

def f1(x,c):
    pass

def f2(L,R):
    pass


for _ in range(Q):
    command,x1,x2=input().split()
    if command==1:
        x1=int(x1)-1
        f1(x1,x2)
    else:
        x1=int(x1)-1
        x2=int(x2)-1
        if f2(x1,x2):
            print("Yes")
        else:
            print("No")