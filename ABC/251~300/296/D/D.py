import math
n, m = map(int, input().split())
if n ** 2 < m:
    print(-1)
elif m <= n:
    print(m)
else:
    k = int(math.sqrt(m))
    if k**2 == m and k <= n:
        print(m)
    else:
        k += 1
        s = k ** 2 - m
        l = int(math.sqrt(s))
        if k + l <= n:
            t = (k + l) * (k - l)
        else:
            t = n * (2 * k - n)
        ans = t
        for a in range(2, min(n+1, min(t, int(math.sqrt(t))+1000000))):
            if m % a == 0 and m // a <= n:
                print(m)
                break
            if m // a + 1 <= n:
                ans = min(ans, (m // a + 1) * a)
        else:
            print(ans)
            
    