N = int(input())
S = []
for _ in range(N):
    S.append(input())

def kaibun(s):
    n = len(s)
    for i in range((n+1)//2):
        if s[i] != s[-(i+1)]:
            return False
    return True

for i in range(N):
    for j in range(N):
        if i==j: continue
        if kaibun(S[i] + S[j]):
            print("Yes")
            exit()
print("No")
        
        