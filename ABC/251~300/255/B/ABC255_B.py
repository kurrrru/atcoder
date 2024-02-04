import math

n,k = map(int,input().split())
a = list(map(int, input().split()))
x = [0] * n
y = [0] * n
for i in range(n):
    x[i],y[i]=map(int,input().split())
dis = 0

b = [1000000000000]*n

for i in range(k):
    for j in range(n):
        #a[i]とjの距離
        new_dis=(x[a[i]-1] - x[j])**2 + (y[a[i]-1] - y[j])**2
        if b[j] > new_dis:
            b[j] = new_dis
for i in range(n):
    if dis < b[i]:
        dis = b[i]

print(math.sqrt(dis))
