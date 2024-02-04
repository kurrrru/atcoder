import random
N=random.randint(1,20)
l=[[i] for i in range(N)]
k=N
print(N)
while k>1:
    i=random.randint(0,k-1)
    i1=random.randint(0,len(l[i])-1)    
    j=random.randint(0,k-1)
    j1=random.randint(0,len(l[j])-1)
    if i==j: continue
    print(l[i][i1]+1,l[j][j1]+1)
    l[i]+=l[j]
    l.pop(j)
    k-=1
    