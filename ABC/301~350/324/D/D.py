from collections import Counter
N=int(input())
S=list(map(int,list(input())))
C=Counter(S)
cnt=0
for i in range(int(1e13**(0.5))+1):
    a=str(i**2)
    if len(a)>N:
        break
    D=Counter(list(map(int,a)))
    for j in range(1,10):
        if C[j]!=D[j]:
            break
    else:
        cnt+=1
print(cnt)
