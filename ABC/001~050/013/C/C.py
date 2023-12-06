# WA x 2
import math
n, h = map(int,input().split())
a, b, c, d, e = map(int,input().split())
need = n * e - h
b+=e
d+=e
# min(a*x+c*y), x+y<=n, b*x+d*y>need, x>=0, y>=0
m = math.inf
# y>(need-b*x)/d, x=0 to need//b+1
for x in range(n+1):
    y = (need - b * x) // d + 1
    if y>=0 and x+y<=n and a*x+c*y<m:
        m = a * x + c * y
if m == math.inf:
    m = 0
print(m)