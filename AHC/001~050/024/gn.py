import random


def main():
    n=50
    m=100
    c=[[0 for _ in range(n)] for _ in range(n)]
    zero=[]
    for i in range(n):
        for j in range(n):
            zero.append((i,j))
    for k in range(1,m+1):
        index=random.randint(0,len(zero)-1)
        i,j=zero[index]
        c[i][j]=k
        zero.remove((i,j))
    while zero:
        index=random.randint(0,len(zero)-1)
        i,j=zero[index]
        di,dj = [(0,1),(0,-1),(1,0),(-1,0)][random.randint(0,3)]
        if not (0<=i+di<n and 0<=j+dj<n) or c[i+di][j+dj]==0: continue
        c[i][j]=c[i+di][j+dj]
        zero.remove((i,j))
    print(n,m)
    for i in range(n):
        print(*c[i])

if __name__=="__main__":
    main()