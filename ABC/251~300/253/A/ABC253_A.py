a,b,c = map(int, input().split())
if (a < b < c) or (c < b < a):
    print("Yes")
elif a==b or b==c:
    print("Yes")
else:
    print("No")