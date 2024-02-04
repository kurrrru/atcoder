n=int(input())
a=list(map(int,input().split()))
q=int(input())
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        k, x = query[1], query[2]
        a[k-1]=x
    else:
        k = query[1]
        print(a[k-1])