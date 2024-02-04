n = int(input())
a = list(map(int, input().split()))
b = [a[i] + i for i in range(n)]
c = [j - a[j] for j in range(n)]
b.sort()
c.sort()

i = 0
j = 0
b1 = 0
c1 = 0
tmp = -1
cnt = 0

while i < n and j < n:
    b1 = 0
    c1 = 0
    if b[i] < c[j]:
        i += 1
        continue
    if b[i] > c[j]:
        j += 1
        continue
    if b[i] == c[j]:
        tmp = b[i]
        while i < n and b[i] == tmp:
            b1 += 1
            i += 1
        while j < n and c[j] == tmp:
            c1 += 1
            j += 1
        cnt += b1 * c1
print(cnt)
    