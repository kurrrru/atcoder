# 006 - Smallest Subsequence (★★★★★☆☆)

# 辞書順は貪欲法、nexという前処理

n, k = map(int, input().split())
s = input()

alphabet = "abcdefghijklmnopqrstuvwxyz"

nex = [[- 1] * 26 for _ in range(n)]
for i in range(n - 1, - 1, - 1):
    for j in range(26):
        if alphabet[j] == s[i]:
            nex[i][j] = i
        else:
            if i < n - 1:
                nex[i][j] = nex[i + 1][j]

ans = ""
j = - 1 # 最後に取った文字の添字

for i in range(k):
    for l in range(26):
        if j + 1 < n and nex[j + 1][l] >= 0 and n - nex[j + 1][l] >= k - i:
            j = nex[j + 1][l]
            ans += s[j]
            break

print(ans)