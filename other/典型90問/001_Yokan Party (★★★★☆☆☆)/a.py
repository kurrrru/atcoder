# 001 - Yokan Party (★★★★☆☆☆)

# 最小値の最大値を求める問題は、「2分探索」を行う。

n, l = map(int, input().split())
k = int(input())
a_ = [0] + list(map(int, input().split())) + [l]
a = [a_[i + 1] - a_[i] for i in range(n+1)] 

left = 0
right = l 
mid = (left + right) // 2

while left < right - 1:
    cutnum = 0
    length = 0
    for i in range(n+1):
        length += a[i]
        if length >= mid:
            if cutnum == k:
                continue
            length = 0
            cutnum += 1
    if cutnum < k or length < mid:
        right = mid
    else:
        left = mid
    mid = (left + right) // 2
   
print(mid)

