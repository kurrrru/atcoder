n, q = map(int, input().split())

ff = {}

def follow(a,b):
    global ff
    if a in ff:
        ff[a].add(b)
    else:
        ff[a] = {b}
        
def not_follow(a,b):
    global ff
    if a in ff:
        if b in ff[a]:
            ff[a].remove(b)
    
def check(a,b):
    if a in ff and b in ff:
        if b in ff[a] and a in ff[b]:
            return True
    return False

for i in range(q):
    t, a, b = map(int, input().split())
    if t == 1:
        follow(a, b)
    elif t == 2:
        not_follow(a, b)
    else:
        if check(a, b):
            print("Yes")
        else:
            print("No")
    