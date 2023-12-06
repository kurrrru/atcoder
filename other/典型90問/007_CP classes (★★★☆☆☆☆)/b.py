# 007 - CP Classes (★★★☆☆☆☆)

# 二分探索をbisectを使って行う
# bisect.bisect_left(A, b)は、A[k] > bとなる最小のkを探す

import bisect
n = int(input())
a = list(map(int, input().split()))
a.sort()
q = int(input())
for _ in range(q):
    b = int(input())
    r = bisect.bisect_left(a, b)
    l = r - 1
    if r >= n:
        print(abs(a[l] - b))
    elif l < 0:
        print(abs(a[r] - b))
    elif abs(a[r] - b) < abs(a[l] - b):
        print(abs(a[r] - b))
    else:
        print(abs(a[l] - b))
    