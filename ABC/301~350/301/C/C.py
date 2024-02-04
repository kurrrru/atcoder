#301-C
from collections import Counter

S=input()
T=input()
a=[]
b=[]
for i in range(len(S)):
    if S[i] in "atcoder@":
        a.append(S[i])
    if T[i] in "atcoder@":
        b.append(T[i])
al="atcoder@"
ad=Counter(a)
bd=Counter(b)
cnta=0
cntb=0
for c in "atcoder":
    if c in ad and c in bd:
        if ad[c]>bd[c]:
            cntb+=ad[c]-bd[c]
        else:
            cnta+=bd[c]-ad[c]
    elif c in ad:
        cntb+=ad[c]
    else:
        cnta+=bd[c]
if "@" in ad:
    adat=ad["@"]
else:
    adat=0
if "@" in bd:
    bdat=bd["@"]
else:
    bdat=0
if cnta<=adat and cntb<=bdat and len(a)==len(b):
    print("Yes")
else:
    print("No")

