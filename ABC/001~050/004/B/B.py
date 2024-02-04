c=[""]*4
for i in range(4):
    c[3-i]=input()[::-1]
for i in range(4):
    print(c[i])