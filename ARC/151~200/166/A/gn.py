T=10
from random import randint
print(T)
for i in range(T):
    N=randint(1,2)
    X=[]
    Y=[]
    for j in range(N):
        X.append("ABC"[randint(0,2)])
        Y.append("ABC"[randint(0,2)])
    print(N,"".join(X),"".join(Y))
