import random 
M=random.randint(1,100)
print(M)
for i in range(3):
    s=[]
    for j in range(M):
        s.append(str(random.randint(0,9)))
    print("".join(s))
