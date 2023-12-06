N=int(input())
s=[]
for i in range(N+1):
    for j in range(1,10):
        if N%j==0 and i%(N//j)==0:
            s.append(str(j))
            break
    else:
        s.append("-")
print("".join(s))

