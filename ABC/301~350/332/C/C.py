# AC
N,M=map(int,input().split())
S=list(input())
t=M
add=0
ans=0
for i in range(N):
    if S[i]=="0":
        t=M
        ans=max(add,ans)
        add=0
    elif S[i]=="1":
        if t>0:
            t-=1
        else:
            add+=1
    else:
        add+=1
ans=max(ans,add)
print(ans)