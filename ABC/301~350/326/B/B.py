import bisect
l=[]
for N in range(100,1000):
    a=N//100
    b=(N//10)%10
    c=N%10
    if a*b==c:
        l.append(N)


N=int(input())
print(l[bisect.bisect_left(l,N)])