N=int(input())
q=[[] for _ in range(37)]
for i in range(N):
    C=int(input())
    A=list(map(int,input().split()))
    for j in range(C):
        q[A[j]].append([i+1,C])
X=int(input())
if len(q[X])==0:
    print(0)
    print("")
    exit()
m=min(q[X],key=lambda x:x[1])[1]
ans=[]
for i in range(len(q[X])):
    if q[X][i][1]==m:
        ans.append(str(q[X][i][0]))
print(len(ans))
print(" ".join(ans))
        
