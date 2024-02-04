import math
a, b = map(int, input().split())
if a > b:
    a, b = b, a
if b > a * 2 / math.sqrt(3):
    print(a * 2 / math.sqrt(3))
else:
    print(math.sqrt(4*(a**2+b**2)-4*math.sqrt(3)*a*b))