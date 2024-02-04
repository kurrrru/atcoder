n = int(input())
a = list(map(int, input().split()))
aCopy = [a[i] for i in range(n)]
div2 = [0 for _ in range(n)]
div3 = [0 for _ in range(n)]

ans = 0
for i in range(n):
    while aCopy[i] % 2 == 0:
        aCopy[i] = aCopy[i] // 2
        div2[i] += 1
    while aCopy[i] % 3 == 0:
        aCopy[i] = aCopy[i] // 3
        div3[i] += 1
    if aCopy[0] != aCopy[i]:
        ans = - 1
        break 

if ans == 0:
    ans = sum(div2) - min(div2) * n + sum(div3) - min(div3) * n


print(ans)