N=int(input())
P=[]
d={}
M=1000000000000000000000
for i in range(N):
    A,B=map(int,input().split())
    P.append(A*M//(A+B))
    if A*M//(A+B) in d:
        d[A*M//(A+B)][0].append(str(i+1))
    else:
        d[A*M//(A+B)]=[[str(i+1)],0]
P.sort(reverse=True)
ans=[]
for i in range(N):
    ans.append(d[P[i]][0][d[P[i]][1]])
    d[P[i]][1]+=1

print(" ".join(ans))