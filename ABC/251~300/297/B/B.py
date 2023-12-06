s=input()
d={}
for i in range(8):
    if not s[i] in d:
        d[s[i]]=[i]
    else:
        d[s[i]].append(i)
if (d["B"][0] + d["B"][1]) % 2 == 1 and d["R"][0] < d["K"][0] < d["R"][1]:
    print("Yes")
else:
    print("No")
    