N=int(input())
if N%2: print()
for i in range(1 << N):
    v = 0
    ans = []
    for j in range(N-1, -1, -1):
        if i & (1 << j):
            v -= 1
            ans.append(")")
        else:
            v += 1
            ans.append("(")
        if v < 0:
            break
    else:
        if v == 0:
            print("".join(ans))
        