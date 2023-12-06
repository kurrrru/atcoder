n = int(input())
a = list(map(int, input().split()))
q = int(input())

base = - 1
sp = {}

def allInput(x):
    global base, sp
    base = x
    sp = {}

def add(i, x):
    global sp
    if i in sp:
        sp[i] += x
    else:
        if base == - 1:
            sp[i] = a[i] + x
        else:
            sp[i] = base + x

def out(i):
    if i in sp:
        print(sp[i])
    else:
        if base == - 1:
            print(a[i])
        else:
            print(base)

for i in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        allInput(query[1])
    elif query[0] == 2:
        add(query[1] - 1, query[2])
    else:
        out(query[1] - 1)
    