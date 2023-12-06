s = input()
for i in range(len(s)):
    if s[i] in "QWERTYUIOPASDFGHJKLZXCVBNM":
        print(i+1)
        break