n, m, h, k = map(int, input().split())
s = input()
item = set()
now = [0,0]
for _ in range(m):
    x, y = map(int, input().split())
    item.add((x,y))
    
def move(s, now):
    if s == "R":
        now[0] += 1
    elif s == "L":
        now[0] -= 1
    elif s == "U":
        now[1] += 1
    elif s == "D":
        now[1] -= 1


for i in range(n):
    h -= 1
    move(s[i], now)
    if h < 0:
        print("No")
        break
    if h < k and (now[0], now[1]) in item:
        h = k
        item.remove((now[0], now[1]))
else:
    print("Yes")
        
    
    