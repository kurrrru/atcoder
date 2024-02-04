import random
n, k = map(int, input().split())
s = input()
nx = 0
ny = 0
py = []
pny = []
px = []
pnx = []
for i in range(len(s)):
    if s[i] == "X":
        nx += 1
        px.append(i)
        if nx >= 2:
            pnx.append(px[nx - 1] - px[nx - 2])
    elif s[i] == "Y":
        ny += 1
        py.append(i)
        if ny >= 2:
            pny.append(py[ny - 1] - py[ny - 2])
if ny == 0:
    if k == 0:
        print(0)
    else:
        print(k-1)
elif nx == 0:
    if k == n:
        print(0)
    else:
        print(n - k - 1)
elif k <= nx:
    pny.sort()
    cnt = 0
    for i in range(len(pny)):
        if pny[i] == 1:
            cnt += 1
        else:
            if k == 0:
                break
            elif k < pny[i] - 1:
                cnt += k
                k = 0
            else:
                cnt += pny[i]
                k -= pny[i] - 1
    if k > 0:
        cnt += k
    print(cnt)
else:
    pnx.sort(reverse = True)
    cnt = 0
    k = k - nx
    if px[0] + n - px[-1] - 1 >= k:
        print(n - 1 - k)
    else:
        cnt = px[0] + n - px[-1] - 1
        k = k - (px[0] + n - px[-1] - 1)
        for i in range(len(pnx)):
            if k == 0:
                break
            if pnx[i] - 1 > k:
                cnt += k + 1
                k = 0
            else:
                cnt += pnx[i]
                k = k - (pnx[i] - 1)
        cnt = n - 1 - cnt
        print(cnt)