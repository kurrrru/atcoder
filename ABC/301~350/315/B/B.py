M=int(input())
D=list(map(int,input().split()))
S=sum(D)//2+1
for i in range(M):
    if S>D[i]:
        S-=D[i]
    else:
        print(i+1,S)
        break
