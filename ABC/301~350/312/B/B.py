N,M=map(int,input().split())
S=[""]*N
for i in range(N):
    S[i]=list(input())
for a in range(N-8):
    for b in range(M-8):
        for i in range(9):
            for j in range(9):
                if i<3 and j<3 and S[a+i][b+j]!="#":
                    break
                if i>=6 and j>=6 and S[a+i][b+j]!="#":
                    break
                if ((i==3 and j<=3) or (i<=3 and j==3)) and S[a+i][b+j]!=".":
                    break
                if ((i==5 and j>=5) or (i>=5 and j==5)) and S[a+i][b+j]!=".":
                    break
            else:
                continue
            break
        else:
            print(a+1,b+1)