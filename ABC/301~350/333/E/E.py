# AC
N=int(input())
T=[0]*N
X=[0]*N
for i in range(N):
    T[i],X[i] = map(int,input().split())
    X[i]-=1
take = [False] * N
mons = [0] * N
for i in range(N-1, -1, -1):
    if T[i] == 2:
        mons[X[i]] -= 1       

    elif T[i] == 1:
        if mons[X[i]] < 0:
            take[i] = True
            mons[X[i]] += 1
if min(mons) < 0:
    print(-1)
else:
    potion = [0] * (N+1)
    move = []
    for i in range(N):
        if T[i] == 1 and take[i]:
            potion[i+1] = potion[i] + 1
            move.append(1)
        elif T[i] == 2:
            potion[i+1] = potion[i] - 1
        else:
            potion[i+1] = potion[i]
            move.append(0)
    print(max(potion))
    print(*move)