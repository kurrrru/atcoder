s = input()
k = int(input())
r = 0
ans = 0
acc = [0] * (len(s)+1) # acc[len(s)]はacc[-1]のため
if s[0] == ".":
    acc[0] += 1
for i in range(1, len(s)):
    acc[i] = acc[i-1] + (s[i] == ".")

for l in range(len(s)):
    while r < len(s) and acc[r] - acc[l-1] <= k:
        r = r + 1
    ans = max(ans, r - l)
print(ans)