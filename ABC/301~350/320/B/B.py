S=input()
N=len(S)
for l in range(N,0,-1):
    for i in range(N-l+1):
        if S[i:i+l]==S[i+l-1-N:i-1-N:-1]:
            print(l)
            exit()
            