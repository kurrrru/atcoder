# 007 - CP Classes (★★★☆☆☆☆)

n = int(input())
a = list(map(int, input().split()))
a.sort()
q = int(input())
for _ in range(q):
    b = int(input())
    l = 0
    r = n - 1
    while r - l > 1:
        mid = (l + r) // 2
        if a[mid] == b:
            l = mid
            r = mid
            break
        elif a[mid] < b:
            l = mid
        else:
            r = mid
    if abs(a[r] - b) < abs(a[l] - b):
        print(abs(a[r] - b))
    else:
        print(abs(a[l] - b))
    