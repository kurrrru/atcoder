N,X,Y=map(int,input().split())
P=[0]*N
T=[0]*N
for i in range(1,N):
    P[i],T[i]=map(int,input().split())
#lcm(1~8)=840
l=840
t=[i for i in range(l)]
for i in range(l):
    for j in range(1,N):
        #t[i]以上のP[j]の倍数
        s=(t[i]-1)//P[j]*P[j]+P[j]
        t[i]=s+T[j]
    t[i]-=i

# print(t[0],t[1],t[2])
Q=int(input())
for i in range(Q):
    q=int(input())
    q+=X
    q+=t[q%l]
    q+=Y
    print(q)