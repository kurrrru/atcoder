n = int(input())
s = []
l1 = ["H", "D", "C", "S"]
l2 = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"]
out = "Yes"
for _ in range(n):
    t = input()
    if not (t[0] in l1 and t[1] in l2 and (not t in s)):
        out = "No"
        break
    s.append(t)
print(out)