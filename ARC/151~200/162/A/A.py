T=int(input())
for _ in range(T):
    N=int(input())
    P=list(map(lambda x:int(x)-1,input().split()))
    Q=[0]*N
    for i in range(N):
        Q[P[i]]=i
    nowmax = -1
    cnt = 0
    for i in range(N):
        if Q[i]>nowmax:
            nowmax = Q[i]
            cnt += 1
    print(cnt)