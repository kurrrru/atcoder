N=int(input())
A=list(map(lambda x:int(x)-1,input().split()))
B=[[] for _  in range(N)]
for i in range(N):
    B[A[i]].append(i)

c=0
for i in range(N):
    if len(B[i])<=1:
        continue
    t=0
    x=0
    s=0
    for j in range(1,len(B[i])):
        if B[i][j-1]+1==B[i][j]:
            t+=1
            s+=1
        else:
            t=0
            x+=t*(t+1)//2
    x+=t*(t+1)//2
    # print(c,x,s)
    u=len(B[i])
    c+=(B[i][-1]-B[i][0]-len(B[i])+2)*((u-2)*(u-3)//2)-len(B[i])*(len(B[i])-1)//2+x
print(c)
# print(B)