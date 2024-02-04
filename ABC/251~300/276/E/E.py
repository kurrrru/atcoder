h, w = map(int, input().split())
c = [[] for _ in range(h)]
for i in range(h):
    c[i] = list(input())
    if "S" in c[i]:
        si, sj = i, c[i].index("S")
flag = [[False for _ in range(w)] for _ in range(h)]
stack = []
ans = "No"
# (i, j)->(i-1,j)(i+1,j)(i,j-1)(i,j+1)
if si - 1 >= 0 and c[si - 1][sj] == ".":
    stack.append((si - 1, sj))
if si + 1 < h and c[si + 1][sj] == ".":
    stack.append((si + 1, sj))
if sj - 1 >= 0 and c[si][sj - 1] == ".":
    stack.append((si, sj - 1))
if sj + 1 < w and c[si][sj + 1] == ".":
    stack.append((si, sj + 1))
cnt = 1
while len(stack) > 0:
    cnt += 1
    i, j = stack.pop()
    if flag[i][j] == False:
        cnt = 1
        flag[i][j] = True
    if i - 1 >= 0 and flag[i - 1][j] == False:
        if c[i - 1][j] == ".":
            stack.append((i - 1, j))
            flag[i - 1][j] = True
        elif c[i - 1][j] == "S" and cnt >= 4:
            ans ="Yes"
            break  
    if i + 1 < h and flag[i + 1][j] == False:
        if c[i + 1][j] == ".":
            stack.append((i + 1, j))
            flag[i + 1][j] = True
        elif c[i + 1][j] == "S" and cnt >= 4:
            ans ="Yes"
            break
    if j - 1 >= 0 and flag[i][j - 1] == False:
        if c[i][j - 1] == ".":
            stack.append((i, j - 1))
            flag[i][j - 1] = True
        elif c[i][j - 1] == "S" and cnt >= 4:
            ans ="Yes"
            break
    if j + 1 < w and flag[i][j + 1] == False:
        if c[i][j + 1] == ".":
            stack.append((i, j + 1))
            flag[i][j + 1] = True
        elif c[i][j + 1] == "S" and cnt >= 4:
            ans ="Yes"
            break
print(ans)