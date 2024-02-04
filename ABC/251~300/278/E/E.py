H, W, N, h, w = map(int, input().split())
a = [[] for _ in range(H)]
c = {}


for i in range(H):
    a[i] = list(map(int, input().split()))
    for j in range(W):
        if i >= h or j >= w:
            if a[i][j] in c:
                c[a[i][j]] += 1
            else:
                c[a[i][j]] = 1

ans = [[0 for _ in range(W - w + 1)] for _ in range(H - h + 1)]
ans[0][0] = len(c)

for i in range(H - h + 1):
    for j in range(W - w + 1):
        if j == 0:
            if i == 0:
                continue
            else:
                for i1 in range(i - 1, i - 1 + h):
                    for j1 in range(W - w, W):
                        if a[i1][j1] in c:
                            c[a[i1][j1]] += 1
                        else:
                            c[a[i1][j1]] = 1
                for i1 in range(i, i + h): 
                    for j1 in range(w):
                        if c[a[i1][j1]] == 1:
                            c.pop(a[i1][j1])
                        else:
                            c[a[i1][j1]] -= 1
        else:
            for i1 in range(i, i + h):
                if a[i1][j - 1] in c:
                    c[a[i1][j - 1]] += 1
                else:
                    c[a[i1][j - 1]] = 1
                if c[a[i1][j + w - 1]] == 1:
                    c.pop(a[i1][j + w - 1])
                else:
                    c[a[i1][j + w - 1]] -= 1
        ans[i][j] = len(c)
    print(" ".join(list(map(str, ans[i]))))

