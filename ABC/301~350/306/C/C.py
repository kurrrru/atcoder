n=int(input())
a=list(map(int, input().split()))
cnt=[0]*(n+1)
d=[]
for i in range(n*3):
    cnt[a[i]]+=1
    if cnt[a[i]]==2:
        d.append(str(a[i]))
print(" ".join(d))