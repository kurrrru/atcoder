XA,YA,XB,YB,XC,YC=map(int,input().split())
XA-=XB
YA-=YB
XC-=XB
YC-=YB
if XC<0: XA,XC=-XA,-XC
if YC<0: YA,YC=-YA,-YC
if XC==0:
    if XA==0 and YA>0:
        print(abs(XA)+abs(YA+1)+YC+2)
    else:
        print(abs(XA)+abs(YA+1)+YC)
elif YC==0:
    if YA==0 and XA>0:
        print(abs(XA+1)+abs(YA)+XC+2)
    else:
        print(abs(XA+1)+abs(YA)+XC)
else:
    if XA==0 and YA>0:
        route1=abs(XA)+abs(YA+1)+YC+2+XC+2
        route2=abs(XA+1)+abs(YA)+XC+2+YC
    elif YA==0 and XA>0:
        route1=abs(XA)+abs(YA+1)+YC+2+XC
        route2=abs(XA+1)+abs(YA)+XC+2+YC+2
    else:
        route1=abs(XA)+abs(YA+1)+YC+2+XC
        route2=abs(XA+1)+abs(YA)+XC+2+YC
    print(min(route1,route2))