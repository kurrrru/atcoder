N,M=map(int,input().split())
for z in range(N+1):
    y=(M-4*z)-2*(N-z)
    x=N-y-z
    if x>=0 and y>=0 and z>=0:
        print(x,y,z)
        break
else:
    print(-1,-1,-1)