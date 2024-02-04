n = int(input())
a = list(map(int, input().split()))
cnt = 0
d = {}
for i in range(n):
    if not a[i] in d:
        d[a[i]] = 1
    elif d[a[i]] == 1:
        d[a[i]] = 0
        cnt += 1
    else:
        d[a[i]] = 1
print(cnt)