S=[100]+list(map(int,input().split()))+[675]
for i in range(1, 10):
    if S[i-1]>S[i] or S[i]%25!=0:
        print("No")
        exit()
print("Yes")