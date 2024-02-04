#WA
def f(s, a, n):
    cnt = 0
    b = len(str(a))
    if s > a:
        return 0
    if int((str(a))[:n]) >= s and len(str(s)) == n and s != 0:
        cnt += int(pow(10, b-n))
    if len(str(s)) == n:
        cnt += int(pow(10, b-n-1)) * (b-n) * (int((str(a))[0]) + 1)
    else:
        cnt += int(pow(10, b-n-1)) * (b-n) * (int((str(a))[0]) + 1) - (10**(b-n-1)//9)
    cnt += 1
    return cnt



t = int(input())
for _ in range(t):
    s, l, r = input().split()
    n = len(s)
    s = int(s)
    l = int(l)
    r = int(r)
    if n > len(str(r)):
        print(0)
        continue
    print(f(s, r, n) - f(s, l, n))
    
    

    