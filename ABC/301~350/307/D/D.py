N = int(input())
S = input()

l = []

a = [0 for _ in range(N)]
for i in range(N-1, -1, -1):
    if S[i] == ")":
        l.append(i)
    elif S[i] == "(":
        if len(l)==0:
            continue
        s = l.pop()
        a[s] = 1
        a[i] = -1

c = 0
s = -1
t = -1
for i in range(N-1, -1, -1):
    if a[i] == 1:
        if s == -1:
            s = i
        c += 1
    elif a[i] == -1:
        c -= 1
        if c == 0:
            t = i
            if s == N-1:
                S = S[:t]
            else:
                S = S[:t] + S[s+1:]
            s = -1
            t = -1

print(S)        
            
    