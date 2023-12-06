n=int(input())
s = input()
c=0
for i in range(n):
    if s[i]=="x":
        print("No")
        break
    elif s[i]=="o":
        c+=1
else:
    if c>=1:
        print("Yes")
    else:
        print("No")
