n,a,b,c,d = map(int, input().split())
if a > 0 and b == 0 and c == 0 and d > 0:
    print("No")
else:
    if abs(b-c) <= 1:
        print("Yes")
    else:
        print("No")