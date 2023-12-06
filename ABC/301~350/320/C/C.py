N=int(input())
S1=input()*3
S2=input()*3
S3=input()*3
S=[S1,S2,S3]
first=[[[] for _ in range(3)] for _ in range(10)]
a=[N*10]*10

for x in range(10):
    for i in range(3*N):
        for j in range(3):
            if int(S[j][i])==x:
                if len(first[x][j])<3:
                    first[x][j].append(i)
    if not (len(first[x][0])>0 and len(first[x][1])>0 and len(first[x][2])>0):
        continue
    for i in range(max(first[x][0][-1],first[x][1][-1],first[x][2][-1])+1):
        for l in first[x][0]:
            for m in first[x][1]:
                for n in first[x][2]:
                    if l>i or m>i or n>i:
                        continue
                    if l!=m and l!=n and m!=n:
                        a[x]=i
                        break
                else:
                    continue
                break
            else:
                continue
            break
        else:
            continue
        break
m=min(a)
if m==N*10:
    print(-1)
else:
    print(m)
            