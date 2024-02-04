A,B=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
dp1=[[0 for _ in range(B+1)] for _ in range(A+1)]
dp2=[[0 for _ in range(B+1)] for _ in range(A+1)]
#dp1[i][j]: a[0...i-1],b[1...j-1]が取られているときのすぬけ君の最大値

for i in range(B):
    match (A+B-i)%2:
        case 1:
            dp1[0][i+1]=dp1[0][i]+b[B-i-1]
            dp2[0][i+1]=dp2[0][i]
        case 0:
            dp1[0][i+1]=dp1[0][i]
            dp2[0][i+1]=dp2[0][i]+b[B-i-1]
                     
for i in range(A):
    match (A+B+i)%2:
        case 1:
            dp1[i+1][0]=dp1[i][0]+a[A-i-1]
            dp2[i+1][0]=dp2[i][0]
        case 0:
            dp1[i+1][0]=dp1[i][0]
            dp2[i+1][0]=dp2[i][0]+a[A-i-1]
            

for i in range(A):
    for j in range(B):
        match (A+B+i+j)%2:
            case 1:
                #すめけ
                if dp2[i][j+1]+a[A-i-1]>dp2[i+1][j]+b[B-j-1]:
                    dp1[i+1][j+1]=dp1[i][j+1]
                    dp2[i+1][j+1]=dp2[i][j+1]+a[A-i-1]
                else:
                    dp1[i+1][j+1]=dp1[i+1][j]
                    dp2[i+1][j+1]=dp2[i+1][j]+b[B-j-1]
            case 0:
                #すぬけ
                if dp1[i][j+1]+a[A-i-1]>dp1[i+1][j]+b[B-j-1]:
                    dp1[i+1][j+1]=dp1[i][j+1]+a[A-i-1]
                    dp2[i+1][j+1]=dp2[i][j+1]
                else:
                    dp1[i+1][j+1]=dp1[i+1][j]+b[B-j-1]
                    dp2[i+1][j+1]=dp2[i+1][j]
                
print(dp1[A][B])