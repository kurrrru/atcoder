H,W=map(int, input().split())
S=[""]*H
for i in range(H):
    S[i]=input()
snuke="snuke"

for i in range(H):
    for j in range(W):
        for di in range(-1,2):
            for dj in range(-1,2):
                if not (0<=i+di*4<H and 0<=j+dj*4<W):
                    continue
                for k in range(5):
                    if S[i+di*k][j+dj*k]!=snuke[k]:
                        break
                else:
                    for l in range(5):
                        print(i+di*l+1,j+dj*l+1)
                    break
            else:
                continue
            break
        else:
            continue
        break
    else:
        continue
    break