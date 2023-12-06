n, m = map(int, input().split())
c = [0 for _ in range(m)]
a = [[] for _ in range(m)]

for i in range(m):
    c[i] = int(input())
    a[i] = list(map(int, input().split()))
cnt = 0
for i in range(2 ** m):
    s = set()
    for j in range(m):
        if ((i >> j) & 1):
            s = s | set(a[j])
    if s == set(range(1, n + 1)):
        cnt += 1
print(cnt)
            
           