# 002 - Encyclopedia of Parentheses (★★★☆☆☆☆)

# bit全探索
# 0を"("、1を")"と対応させる

n = int(input())
for i in range(1 << n):
    score = 0
    s = ""
    for j in range(n-1, -1, -1):
        if i & (1 << j) == 0:
            score += 1
            s = s + "("
        else:
            score -= 1
            s = s + ")"
            if score < 0:
                break
    if score == 0:
        print(s)