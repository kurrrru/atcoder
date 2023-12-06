n,m = map(int, input().split())
s = [[] for _ in range(n)]
for i in range(n):
    s[i] = list(input())
    for j in range(m):
        if s[i][j] == "o":
            s[i][j] = 1
        else:
            s[i][j] = 0
c = 0
for i in range(n - 1):
    for j in range(i + 1, n):
        for k in range(m):
            if s[i][k] + s[j][k] == 0:
                break
        else:
            c += 1
print(c)