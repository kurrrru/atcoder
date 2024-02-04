h,w=map(int,input().split())
r,c=map(int,input().split())
out=0
if r==1 or r==h:
    out+=1
else:
    out+=2
if c==1 or c==w:
    out+=1
else:
    out+=2
if h==1:
  out -=1
if w==1:
  out -=1

if r<1 or r>h or c<1 or c>w:
  out=0

print(out)
