n = int(input())
a = [[] for _ in range(n)]
b = [[] for _ in range(n)]
for i in range(n):
    a[i] = list(map(int, input().split()))
for i in range(n):
    b[i] = list(map(int, input().split()))

def roll(a):
    c = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[n-1-j][i]
    return c
def check(a,b):
    for i in range(n):
        for j in range(n):
            if a[i][j] == 1 and b[i][j] == 0:
                return False
    return True

for _ in range(4):
    if check(a,b):
        print("Yes")
        break
    a = roll(a)
else:
    print("No")
                
    