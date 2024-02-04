n = int(input())
s = input()
a = s[0]
for i in range(1,n):
  if a == s[i]:
    print("No")
    break
  else:
    a = s[i]
else:
  print("Yes")