N,S,M,L=map(int,input().split())
cost=1000000000
for a in range(N+2):
    for b in range(N+2):
        for c in range(N+2):
            if 6*a+8*b+12*c>=N and S*a+M*b+L*c<cost:
                cost=S*a+M*b+L*c
print(cost)