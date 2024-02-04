N=int(input())
NG1=int(input())
NG2=int(input())
NG3=int(input())
NG=[NG1,NG2,NG3]

ans="NO"

cnt=0
while cnt<100:
    if N in NG:
        break
    elif N==3 or N==2 or N==1:
        ans="YES"
        break
    elif not N-3 in NG:
        N-=3
        cnt+=1
    elif not N-2 in NG:
        N-=2
        cnt+=1
    elif not N-1 in NG:
        N-=1
        cnt+=1
    else:
        break
print(ans)