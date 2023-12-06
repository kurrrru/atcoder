from operator import le


n,q = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
b = [0] * n
for i in range(n):
    b[0] += (a[i]-a[0])

for i in range(1,n):
    b[i] = b[i-1] + (2*i - n) * (a[i] - a[i-1])

for i in range(q):
    x = int(input())
    if a[0]>=x:
        print(b[0] + n * (a[0]-x))
    elif a[n-1] <= x:
        print(b[n-1] + n * (x - a[n-1]))
    else:
        left = 0
        right = n-1
        while left < right:
            center = (left+right)//2
            if a[center]<x:
                left = center+1
            else:
                right = center-1

        ans1 = b[left-1] + (x - a[left-1]) * (2 * left - n)
        ans2 = b[right] + (a[right] - x) * (2 * right - n)
        if ans1 <= ans2:
            print(ans1)
        else:
            print(ans2)