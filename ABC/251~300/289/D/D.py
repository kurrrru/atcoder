n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
x = int(input())

c = [0 for _ in range(x + 1)]
for i in range(m):
    c[b[i]] = - float("inf")
for i in range(n):
    if a[i] <= x:
        c[a[i]] += 1

for i in range(x):
    if c[i] >= 1:
        for j in range(n):
            if i + a[j] <= x:
                c[i + a[j]] += 1
     


if c[x] >= 1:
    print("Yes")
else:
    print("No")
            
