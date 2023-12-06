a=list(map(int, input().split()))
ans=a[63]
for i in range(62,-1,-1):
  ans=ans*2+a[i]
print(ans)