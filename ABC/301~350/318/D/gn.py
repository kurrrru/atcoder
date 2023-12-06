import random
N=random.randint(2,5)
print(N)
for i in range(N-1):
    D=[str(random.randint(1,20)) for _ in range(N-i-1)]
    print(" ".join(D))