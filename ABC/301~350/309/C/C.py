N,K=map(int,input().split())
m = []
for _ in range(N):
    a,b=map(int,input().split())
    m.append([a,b])
m.sort()

t=0
for i in range(N-1,-1,-1):
    m[i][1]+=t
    t=m[i][1]
    if t>K:
        print(m[i][0]+1)
        break
else:
    print(1)
