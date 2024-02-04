n=int(input())
p=list(map(int,input().split()))
pi=[0]*n
for i in range(n):
    pi[p[i]]=i
a=[0]*n
for i in range(n):
    for j in range(n):
        a[j]+=min((i-pi[i]-j)%n,(pi[i]+j-i)%n)
print(min(a))