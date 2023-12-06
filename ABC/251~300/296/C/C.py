n, x = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
i = 0
j = 0
while i < n and j < n:
    if a[i] + x > a[j]:
        j += 1
    elif a[i] + x == a[j]:
        print("Yes")
        break
    else:
        i += 1
else:
    print("No")