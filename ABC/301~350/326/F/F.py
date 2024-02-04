import sys
import bisect
sys.setrecursionlimit(1<<30)
N,X,Y=map(int,input().split())
A=list(map(int,input().split()))
B=A[0::2]
C=A[1::2]

def f(B,Y):
    d1={0:[""]}
    for i in range(len(B)//2):
        d={}
        for k in d1:
            v=d1[k]
            if len(v)<i:
                continue
            d[k+B[i]]=(v+["+"])
            d[k-B[i]]=(v+["-"])
        d1=d
    d2={0:[""]}
    for i in range(len(B)//2,len(B)):
        d={}
        for k in d2:
            v=d2[k]
            if len(v)<i-len(B)//2:
                continue
            d[k+B[i]]=(v+["+"])
            d[k-B[i]]=(v+["-"])
        d2=d
    d2_keys = list(d2.keys())
    d2_keys.sort()
    for i in d1:
        j=bisect.bisect_left(d2_keys,i)
        if i+d2_keys[j]==Y:
            return d1[i]+d2[d2_keys[j]]
    else:
        print("No")
        exit()
Bs=f(B,Y)
Cs=f(C,X)


    
    
