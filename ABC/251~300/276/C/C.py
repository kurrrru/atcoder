n = int(input())
p = list(map(int, input().split()))
# l = [0 for _ in range(n)]

for i in range(n-1, 0, -1):
    if p[i - 1] > p[i]:
        memo = i
        break
# p[memo]未満で最大の数を探す
now = 0
for i in range(memo, n):
    if p[i] < p[memo - 1] and p[i] > now:
        now = p[i]
        m = i
p[m], p[memo - 1] = p[memo - 1], p[m]

a = p[memo::]

a.sort()

for i in range(memo,n):
    p[i] = a.pop()
print(" ".join(list(map(str, p))))



"""
123
132
213
231
312
321
max {i|p[i-1]>p[i])

"""