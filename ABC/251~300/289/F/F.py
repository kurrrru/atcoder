sx, sy = map(int, input().split())
tx, ty = map(int, input().split())
a, b, c, d = map(int, input().split())
if (sx - tx) % 2 != 0 or (sy - ty) % 2 != 0:
    print("No")
