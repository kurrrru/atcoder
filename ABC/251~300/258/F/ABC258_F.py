t=int(input())
s = [0,0]
g = [0,0]
a = [0]*17
sx = [0,1]
sy = [0,1]
gx = [0,1]
gy = [0,1]
for i in range(t):
  b,k,s[0],s[1],g[0],g[1]=map(int,input())
  sx = [s[0]%b,b-s[0]%b]
  sy = [s[1]%b,b-s[1]%b]
  gx = [g[0]%b,b-g[0]%b]
  gy = [g[1]%b,b-g[1]%b]
  
  a[0] = (abs(s[0]-g[0])+abs(s[1]-g[1]))*k
  mina=a[0]
  a[1] = (sx[0]+sy[0]+gx[0]+gy[0])*k+abs((s[0]-sx[0])-(g[0]-gx[0]))+abs((s[1]-sy[0])-(g[1]-gy[0]))
  a[2] = (sx[0]+sy[0]+gx[0]+gy[1])*k+abs((s[0]-sx[0])-(g[0]-gx[0]))+abs((s[1]-sy[0])-(g[1]-gy[1]))
  a[3] = (sx[0]+sy[0]+gx[1]+gy[0])*k+abs((s[0]-sx[0])-(g[0]-gx[1]))+abs((s[1]-sy[0])-(g[1]-gy[0]))
  a[4] = (sx[0]+sy[0]+gx[1]+gy[1])*k+abs((s[0]-sx[0])-(g[0]-gx[1]))+abs((s[1]-sy[0])-(g[1]-gy[1]))
  a[5] = (sx[0]+sy[1]+gx[0]+gy[0])*k+abs((s[0]-sx[0])-(g[0]-gx[0]))+abs((s[1]-sy[1])-(g[1]-gy[0]))
  a[6] = (sx[0]+sy[1]+gx[0]+gy[1])*k+abs((s[0]-sx[0])-(g[0]-gx[0]))+abs((s[1]-sy[1])-(g[1]-gy[1]))
  a[7] = (sx[0]+sy[1]+gx[1]+gy[0])*k+abs((s[0]-sx[0])-(g[0]-gx[1]))+abs((s[1]-sy[1])-(g[1]-gy[0]))
  a[8] = (sx[0]+sy[1]+gx[1]+gy[1])*k+abs((s[0]-sx[0])-(g[0]-gx[1]))+abs((s[1]-sy[1])-(g[1]-gy[1]))
  a[9] = (sx[1]+sy[0]+gx[0]+gy[0])*k+abs((s[0]-sx[1])-(g[0]-gx[0]))+abs((s[1]-sy[0])-(g[1]-gy[0]))
  a[10] = (sx[1]+sy[0]+gx[0]+gy[1])*k+abs((s[0]-sx[1])-(g[0]-gx[0]))+abs((s[1]-sy[0])-(g[1]-gy[1]))
  a[11] = (sx[1]+sy[0]+gx[1]+gy[0])*k+abs((s[0]-sx[1])-(g[0]-gx[1]))+abs((s[1]-sy[0])-(g[1]-gy[0]))
  a[12] = (sx[1]+sy[0]+gx[1]+gy[1])*k+abs((s[0]-sx[1])-(g[0]-gx[1]))+abs((s[1]-sy[0])-(g[1]-gy[1]))
  a[13] = (sx[1]+sy[1]+gx[0]+gy[0])*k+abs((s[0]-sx[1])-(g[0]-gx[0]))+abs((s[1]-sy[1])-(g[1]-gy[0]))
  a[14] = (sx[1]+sy[1]+gx[0]+gy[1])*k+abs((s[0]-sx[1])-(g[0]-gx[0]))+abs((s[1]-sy[1])-(g[1]-gy[1]))
  a[15] = (sx[1]+sy[1]+gx[1]+gy[0])*k+abs((s[0]-sx[1])-(g[0]-gx[1]))+abs((s[1]-sy[1])-(g[1]-gy[0]))
  a[16] = (sx[1]+sy[1]+gx[1]+gy[1])*k+abs((s[0]-sx[1])-(g[0]-gx[1]))+abs((s[1]-sy[1])-(g[1]-gy[1]))
  for j in range(17):
    if a[j]<mina:
      mina=a[j]
  print(mina)
    
  