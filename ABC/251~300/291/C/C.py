n = int(input())
s = input()
f = [[] for _ in range(2*n+1)]
f[n].append(0)
x = 0
y = 0
for i in range(n):
    if s[i] == "R":
        x += 1
    elif s[i] == "L":
        x -= 1
    elif s[i] == "U":
        y += 1
    elif s[i] == "D":
        y -= 1
    if y in f[x+n]:
        print("Yes")
        break
    else:
        f[x+n].append(y)
else:
    print("No")