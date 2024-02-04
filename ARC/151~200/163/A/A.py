T=int(input())
def check(N,S):
    for i in range(N-1,0,-1):
        if S[i]>S[0]:
            return True
        elif S[i]==S[0]:
            if S[i:]>S[0:i]:
                return True
    return False

for i in range(T):
    N=int(input())
    S=input()
    if check(N,S):
        print("Yes")
    else:
        print("No")