N=int(input())
S=input()
jewelry="b"
for i in range(1,N+1):
    if i%3==1: jewelry="a"+jewelry+"c"
    elif i%3==2: jewelry="c"+jewelry+"a"
    else: jewelry="b"+jewelry+"b"
    if jewelry==S:
        print(i)
        exit()
print(-1)
