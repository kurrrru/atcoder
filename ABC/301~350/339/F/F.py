import bisect

N=int(input())
A=[int(input()) for _ in range(N)]
A.sort()
ans = 0
for i in range(N):
    for j in range(i, N):
        tmp = A[i] * A[j]
        k = bisect.bisect_left(A, tmp)
        l = bisect.bisect_left(A, tmp + 1)
        if k < l:
            if i == j:
                ans += l - k
            else:
                ans += 2 * (l - k)
print(ans)