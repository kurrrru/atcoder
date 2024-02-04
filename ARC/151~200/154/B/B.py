n = int(input())
s = list(input())
t = list(input())

if sorted(s) != sorted(t):
    print(- 1)
else:
    ti = n - 1
    for i in range(n - 1, - 1, - 1):
        while ti >= 0:
            if t[ti] != s[i]:
                ti -= 1
            if t[ti] == s[i]:
                ti -= 1
                break
        if ti < 0:
            if s[i] != t[0]:
                i += 1
            break
    print(i)
    