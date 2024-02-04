n = int(input())
s = list(input())
c = 0
for i in range(n):
    if s[i] == '"':
        c = (c + 1) % 2
    elif s[i] == ',' and c == 0:
        s[i] = '.'
print("".join(s))

