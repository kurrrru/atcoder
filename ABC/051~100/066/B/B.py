#066-B
S=input()
N=len(S)
for i in range((N+1)//2-1,0,-1):
    if S[:i]==S[i:2*i]:
        print(2*i)
        exit()