s = list(map(int, list(input())))
n = len(s)
zerocounter = 0
ans = n

for i in range(n):
    if s[i] == 0:
        ans -= zerocounter
        zerocounter^=1
    else:
        zerocounter=0

print(ans)