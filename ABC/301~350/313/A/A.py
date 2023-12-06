N=int(input())
P=list(map(int,input().split()))
if N==1 or (max(P)!=max(P[1:]) and P[0]==max(P)):
    print(0)
else:
    print(max(P)-P[0]+1)