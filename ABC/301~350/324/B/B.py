N=int(input())
N//=N&(-N)
while N%3==0:
    N//=3
if N==1:
    print("Yes")
else:
    print("No")