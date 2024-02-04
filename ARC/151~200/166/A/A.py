T=int(input())
for _ in range(T):
    N,X,Y=input().split()
    N=int(N)
    X=list(X)
    if len(X)!=len(Y):
        print("No")
        continue
    for i in range(len(X)):
        if (X[i],Y[i]) in [("A","C"),("B","C")]:
            print("No")
            break
    else:
        l=[[0,0,-1]]
        Xa=0
        Ya=0
        for i in range(N):
            if Y[i]=="A":
                Ya+=1
            if X[i]=="A":
                Xa+=1
            if Y[i]=="C":
                l.append([Ya-Xa,0,i])
                Xa=0
                Ya=0
        l.append((Ya-Xa,0,N))
        for k in range(1,len(l)):
            a,b,i=l[k]
            for j in range(l[k-1][2]+1,i):
                if X[j]!="C": continue
                if a>0:
                    X[j]="A"
                    a-=1
                else:
                    X[j]="B"
        X="".join(X)
        # print(X,Y)
        X=X.split("C")
        Y=Y.split("C")
        # print(X,Y,l)
        b=0
        f=False
        for i in range(len(X)):
            if X[i]>Y[i] or X[i].count("A")!=Y[i].count("A") or len(X[i])!=len(Y[i]):
                print("No")
                break
            for j in range(len(X[i])):
                b+=(Y[i][j]=="B")-(X[i][j]=="B")
                # print(b)
                if b<0:
                    print("No")
                    f=True
                    break
            else:
                continue
            break
        else:
            
            
            print("Yes")