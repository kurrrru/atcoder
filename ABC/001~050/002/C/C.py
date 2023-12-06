xa,ya,xb,yb,xc,yc=map(int,input().split())
xb-=xa
yb-=ya
xc-=xa
yc-=ya
print(abs(xb*yc-yb*xc)/2)