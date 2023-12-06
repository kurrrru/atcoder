D=int(input())
ans=10000000000000
for x in range(int(D**0.5)+1):
    y1=int((D-x**2)**0.5)
    ans=min(abs(D-x**2-y1**2),ans)    
    y2=int((D-x**2)**0.5)+1
    ans=min(abs(D-x**2-y2**2),ans)
print(ans)