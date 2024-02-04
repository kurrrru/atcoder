N=int(input())%30
A=list("123456")
for i in range(N):
    A[i%5],A[i%5+1]=A[i%5+1],A[i%5]
print("".join(A))