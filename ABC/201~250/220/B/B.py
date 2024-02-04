#ABC220_B
def to10(A,k):
    K=1
    ret=0
    while A>0:
        ret+=A%10*K
        A//=10
        K*=k
    return ret
K=int(input())
A,B=map(int,input().split())
print(to10(A,K)*to10(B,K))