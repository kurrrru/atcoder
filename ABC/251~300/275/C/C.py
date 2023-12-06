s = ["" for _ in range(9)]
c = 0
for i in range(9):
    s[i] = input()

def square(x1, y1, x2, y2):
    if x1 == x2 and y1 == y2:
        return False
    if not (s[y1][x1] == "#" and s[y2][x2] == "#"):
        return False 
    x3 = x1 + y2 - y1
    y3 = y1 + x1 - x2
    x4 = x2 + y2 - y1
    y4 = y2 + x1 - x2
    if not (0 <= x3 <= 8 and 0 <= y3 <= 8 and 0 <= x4 <= 8 and 0 <= y4 <= 8):
        return False
    if s[y3][x3] == "#" and s[y4][x4] == "#":
        return True
    return False


for x1 in range(9):
    for y1 in range(9):
        for x2 in range(9):
            for y2 in range(9):
                if square(x1, y1, x2, y2):
                    c += 1


print(c//4)