n = int(input())
a = [0 for _ in range(n)]
b = [0 for _ in range(n)]
c = {}

for i in range(n):
    a[i], b[i] = map(lambda x:int(x) - 1, input().split())
    if a[i] in c:
        c[a[i]].append(b[i])
    else:
        c[a[i]] = [False, b[i]]
    if b[i] in c:
        c[b[i]].append(a[i])
    else:
        c[b[i]] = [False, a[i]]

m = 0 # 現時点での最高階
stack = [0]
while len(stack) > 0:
    s = stack.pop()
    if not s in c:
        continue
    for t in c[s][1:]:
        if t > m:
            m = t
        if not t in c:
            continue
        elif c[t][0] == False:
            stack.append(t)
            c[t][0] = True            

# 最後に1を足す
print(m + 1)