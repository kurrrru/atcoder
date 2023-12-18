N,L = map(int,input().split())
K = int(input())
A = [0] + list(map(int,input().split())) + [L]

l = 0
r = L
while r - l > 1:
    mid = (l + r) // 2
    now_len = 0
    cnt = 0
    for i in range(1, N+2):
        if now_len >= mid and cnt < K:
            now_len = A[i] - A[i-1]
            cnt += 1
        else:
            now_len += A[i] - A[i-1]
    ok = (now_len >= mid) and (cnt == K)
    if ok:
        l = mid
    else:
        r = mid
print(l)