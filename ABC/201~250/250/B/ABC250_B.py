n,a,b=map(int,input().split())
#縦n*a行、横n*b列
tmp=""

for i in range(n):
    tmp=""
    if i%2==0:
        for j in range(n):
            if j%2==0:
                for k in range(b):
                    tmp=tmp+"."
            else:
                for k in range(b):
                    tmp=tmp+"#"
        for j in range(a):
            print(tmp)
    else:
        for j in range(n):
            if j%2==0:
                for k in range(b):
                    tmp=tmp+"#"
            else:
                for k in range(b):
                    tmp=tmp+"."
        for j in range(a):
            print(tmp)
