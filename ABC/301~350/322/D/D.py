P1=[[] for _ in range(4)]
P2=[[] for _ in range(4)]
P3=[[] for _ in range(4)]
P=[P1,P2,P3]
def origin(P:list):
    for i in range(4):
        if "#" in P[i]:
            a1=i
            break
    a2=min([P[i].index("#") if "#" in P[i] else 5 for i in range(4)])    
    ret=[["." for _ in range(4)] for _ in range(4)]
    for i in range(4):
        if a1+i>=4: break
        for j in range(4):
            if a2+j>=4: break
            ret[i][j]=P[a1+i][a2+j]
    return ret

cnt=0
for i in range(3):
    for j in range(4):
        P[i][j]=list(input())
        cnt+=P[i][j].count("#")
    P[i]=origin(P[i])
if cnt!=16:
    print("No")
    exit()

field=[["." for _ in range(300)]for _ in range(300)]


def move(x,y,c,P):
    if c==0:
        for s in range(4):
            for t in range(4):
                if P[s][t]=="#":
                    field[100+x+s][100+y+t]="#"
    elif c==1:
        for s in range(4):
            for t in range(4):
                if P[s][t]=="#":
                    field[100+x-t][100+y+s]="#"

    elif c==2:
        for s in range(4):
            for t in range(4):
                if P[s][t]=="#":
                    field[100+x-s][100+y-t]="#"

    elif c==3:
        for s in range(4):
            for t in range(4):
                if P[s][t]=="#":
                    field[100+x+t][100+y-s]="#"
for num in range(1<<18):
    for i in range(4):
        for j in range(4):
            field[100+i][100+j]="."
    l=[0]*9
    for i in range(9):
        num,l[i]=divmod(num,4)
    x1,y1,c1,x2,y2,c2,x3,y3,c3=l
    move(x1,y1,c1,P[0])
    move(x2,y2,c2,P[1])
    move(x3,y3,c3,P[2])
    # print(field[100:104][100:104])
    for i in range(4):
        for j in range(4):
            if field[100+i][100+j]==".":
                break
        else:
            continue
        break
    else:
        print("Yes")
        break
else:
    print("No")
    