n,q=map(int,input().split())
a=[0]*n
p=[0]*n#x_iと等しい値はa[p[x_i]]にある
for i in range(n):
    a[i]=i
    p[i]=i
#xを受け取ってxと等しい値を探すO(n)
#O(n^2)はきつい
for i in range(q):
    x=int(input())-1
    if p[x]==n-1:
        #右端
        #左と交換
        tmp=a[p[x]-1]
        a[p[x]],a[p[x]-1]=a[p[x]-1],a[p[x]]
        p[x],p[tmp]=p[tmp],p[x]
    else:
        #右端じゃない
        #右と交換
        tmp=a[p[x]+1]
        a[p[x]],a[p[x]+1]=a[p[x]+1],a[p[x]]
        p[x],p[tmp]=p[tmp],p[x]
out =""
for i in range(n):
    out = out + str(a[i]+1)
    if i<=len(a)-2:
        out = out + " " 
print(out)




