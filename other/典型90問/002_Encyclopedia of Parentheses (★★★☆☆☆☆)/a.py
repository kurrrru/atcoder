# 002 - Encyclopedia of Parentheses (★★★☆☆☆☆)

# 深さ優先探索

n = int(input())
if n % 2 == 1:
    exit()
m = n // 2
stack = [("(", 1, 0)]
while stack:
    x, s, t = stack.pop()
    if s == m and t == m:
        print(x)
    elif s == m:
        print(x + ")" * (m - t))
    elif s == t:
        stack.append((x + "(", s + 1, t))
    else:
        stack.append((x + ")", s, t + 1))
        stack.append((x + "(", s + 1, t))