H,W=map(int,input().split())
A=[""]*H
B=[""]*H
for i in range(H):
    A[i]=input()
for i in range(H):
    B[i]=input()
for d1 in range(H):
    for d2 in range(W):
        for i in range(H):
            for j in range(W):
                if A[i][j]!=B[i-d1][j-d2]:
                    break
            else:
                continue
            break
        else:
            print("Yes")
            exit()
print("No")
