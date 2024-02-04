def func1(x,a):
    a.append(x)
    a.sort()

def func2(x,c,a):
    if not x in a:
        return
    left = 0
    right = len(a) - 1
    if a[0] != x:
        while right - left > 1:
            center = (left + right)//2
            if a[center] < x:
                left = center
            else:
                right = center
        tmp = left
    else:
        tmp = -1

    left = 0
    right = len(a) - 1
    if a[right] != x:
        while right - left > 1:
            center = (left + right + 1)//2
            if a[center] <= x:
                left = center
            else:
                right = center
        right -= 1
    

    num_x = right - tmp
    for i in range(min(c,num_x)):
        a.remove(x)

def func3(a):
    print(a[len(a)-1] - a[0]) 


Q = int(input())
a=[]
for i in range(Q):
    q = list(map(int,input().split()))
    if q[0] == 1:
        func1(q[1], a)
    elif q[0] == 2:
        func2(q[1],q[2], a)
    else:
        func3(a)