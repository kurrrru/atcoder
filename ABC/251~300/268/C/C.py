n=int(input())
p=list(map(int,input().split()))
pi=[0]*n
for i in range(n):
  pi[p[i]]=i
a=[0]*n
for i in range(n):
  a[(i-pi[i])%n]+=1
  a[(i-pi[i]+1)%n]+=1
  a[(i-pi[i]-1)%n]+=1
print(max(a))