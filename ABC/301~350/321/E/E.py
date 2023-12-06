import math
T=int(input())
for _ in range(T):
    N,X,K=map(int,input().split())
    if N==1:
        if K==0:
            print(1)
        else:
            print(0)
        continue
    depth=X.bit_length()
    max_depth=N.bit_length()
    max_leaf=1<<(max_depth-1)
    not_leaf=1<<(max_depth-1)-1
    r_leaf=max(0,N-not_leaf-max_leaf//2)
    l_leaf=min(max_leaf//2,N-not_leaf)
    l_flag=(bin(X)[3]=="0")
    ans=2**(K-depth)*(2**(max_depth-K+1)-1)+(depth>K)
    