h,w=map(int, input().split())
s=[[] for _ in range(h)]
for i in range(h):
    s[i] = list(input())

def cnt(i,j): # "."のところ
    ret = 0
    if i>0:
        ret+=(s[i-1][j]=="#")
    if i<h-1:
        ret+=(s[i+1][j]=="#")
    if j>0:
        ret+=(s[i][j-1]=="#")
    if j<w-1:
        ret+=(s[i][j+1]=="#")
    return ret

for i in range(h):
    for j in range(w):
        if s[i][j] == "." and cnt(i,j)>=2:
            print(i+1,j+1)
            exit()