H,W = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(H)]
line = [sum(A[i]) for i in range(H)]
row = [0] * W
for i in range(H):
    for j in range(W):
        row[j] += A[i][j]

ans = [[line[i] + row[j] - A[i][j] for j in range(W)] for i in range(H)]
for i in range(H):
    print(*ans[i])