# AC
def rep(i):
    return int("1"*i)
ans=0
c=0
N=int(input())
for i in range(1,15):
    for j in range(1,i+1):
        for k in range(1,j+1):
            c+=1
            if c==N:
                ans=rep(i)+rep(j)+rep(k)
print(ans)