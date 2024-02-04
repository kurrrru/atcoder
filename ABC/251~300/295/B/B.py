r, a = map(int, input().split())
b = [[] for _ in range(r)]
c = []
for i in range(r):
    b[i] = list(input())
    for j in range(a):
        if b[i][j] != "#" and b[i][j] != ".":
            c.append([i,j,int(b[i][j])])
d=b.copy()
for i in range(r):
    for j in range(a):
        if b[i][j] == "#":
            for k in range(len(c)):
                if abs(c[k][0] - i) + abs(c[k][1] - j) <= c[k][2]:
                    d[i][j] = "."
        else:
            d[i][j] = "."
    print("".join(d[i]))