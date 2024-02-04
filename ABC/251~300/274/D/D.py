n, x, y = map(int, input().split())
a = list(map(int, input().split()))
x = abs(x - a[0])
y = abs(y)


a1 = a[2::2] # x
sa1 = sum(a1)
ax = [0 for _ in range(sa1 + 1)]
ax[a1[0]] = 1
nowmax = a1[0]
tmp = []
for i in range(1, len(a1)):
    tmp = []
    for j in range(nowmax + 1):
        if ax[j] == 1:
            ax[j] = 0
            tmp.append(j + a1[i])
            tmp.append(abs(j - a1[i]))
            # ax[j + a1[i]] = 1
            # ax[abs(j - a1[i])] = 1
    for t in tmp:
        ax[t] = 1    
    nowmax += a1[i]


if (x < len(ax) and ax[x] == 1) or (n == 2 and x==0):
    a2 = a[1::2] # y
    sa2 = sum(a2)
    ay = [0 for _ in range(sa2 + 1)]
    ay[a2[0]] = 1
    nowmax = a2[0]
    for i in range(1, len(a2)):
        tmp = []
        for j in range(nowmax + 1):
            if ay[j] == 1:
                ay[j] = 0
                tmp.append(j + a2[i])
                tmp.append(abs(j - a2[i]))
                # ay[j + a2[i]] = 1
                # ay[abs(j - a2[i])] = 1
        for t in tmp:
            ay[t] = 1
        nowmax += a2[i]
    if y < len(ay) and ay[y] == 1:
        out = "Yes"
    else:
        out = "No"  
else:
    out = "No"
print(out)
