n, k = map(int, input().split())
s = list(input())

for i in range(n):
    if k == 0:
        s[i] = "x"
    else:
        if s[i] == "o":
            k -= 1
print("".join(s))


