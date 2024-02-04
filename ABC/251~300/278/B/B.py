h, m = map(int, input().split())
a = h // 10
b = h % 10
c = m // 10
d = m % 10
if b >= 6:
    e = (a + 1) * 10
    f = 0
else:
    if a == 0 or a == 1 or c <= 3:
        # 時はOK
        e = h
        f = m
    else:
        if b == 5:
            e = (a + 1) * 10
            f = 0
        else:
            e = (h + 1) % 24
            f = 0
print(e, f)