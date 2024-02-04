a = "87654321"
b = "abcdefgh"
for i in range(8):
    s = list(input())
    if "*" in s:
        print(b[s.index("*")]+a[i])
        break