#232-B
import string
S=input()
T=input()
a=string.ascii_lowercase
b=set()
for i in range(len(S)):
    b.add((a.index(S[i])-a.index(T[i]))%26)
print("Yes" if len(b)==1 else "No")