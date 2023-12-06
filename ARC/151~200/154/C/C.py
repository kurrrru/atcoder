def index_multi(l, x):
    return [i for i, _x in enumerate(l) if _x == x]
def check(n, a, b):
    seta = set(a)
    setb = set(b)
    for s in setb:
        if not s in seta:
            return False
    minb = min(b)
    newb = [minb]
    newa = [minb]
    minbi = b.index(minb)
    minai = a.index(minb)
    for i in range(n):
        j = (minbi + i) % n
        if newb[-1] != b[j]:
            newb.append(b[j])
        k = (minai + i) % n
        if newa[-1] != a[k]:
            newa.append(a[k])
    if len(newa) < len(newb):
        return False
    if len(newb) == len(a):
        if a != b:
            return False
        else:
            return True
    minailist = index_multi(newa, minb)
    for i in minailist:
        tmpa = newa[i:] + newa[0:i]
        ti = 0
        last = -1
        for j in range(len(newb)):
            while ti < len(tmpa):
                if tmpa[ti] != newb[j]:
                    ti += 1
                    last = 0
                else:
                    ti += 1
                    last = 1
                    break
            if ti == len(tmpa):
                if j == len(newb)-1 and last == 1:
                    return True
                else:
                    break
        if j == len(newb)-1 and last == 1:
            return True
    return False

t = int(input())
for i in range(t):
    n = int(input())
    a = input().split()
    b = input().split()
    if check(n,a,b):
        print("Yes")
    else:
        print("No")


