N,M=map(int,input().split())
S=input()
T=input()
match (S==T[:N],S==T[M-N:]):
    case (True,True):
        print(0)
    case (True,False):
        print(1)
    case (False,True):
        print(2)
    case (False,False):
        print(3)