def addstr(a,b,c):
    return a+"\n"+str(b)+" "+str(c)

N=int(input())
P=list(map(lambda x: int(x)-1,input().split()))
Q=[-1]*N
for i in range(N):
    Q[P[i]]=i
l=0
r=N-1
ans="Yes"
cnt=0
while l<r:
    if l==Q[l]:
        l+=1
        continue

    elif l<Q[l]<=r-1:
        ans=addstr(ans,Q[l]+1,l)
        cnt+=1
        for i in range(l,Q[l]):
            Q[P[i]]+=2
        P=P[:l]+P[Q[l]:Q[l]+2]+P[l:Q[l]]+P[Q[l]+2:]
        Q[P[l]]=l
        Q[P[l+1]]=l+1
        l+=1
        continue
    
    else:
        if r - l <= 1:
            print("No")
            break
        ans=addstr(ans,r,r-2)
        cnt+=1
        P[r-2],P[r-1],P[r]=P[r-1],P[r],P[r-2]
        Q[P[r]]=r
        Q[P[r-1]]=r-1
        Q[P[r-2]]=r-2
else:
    ans=ans[:3]+"\n"+str(cnt)+ans[3:]
    print(ans)
    