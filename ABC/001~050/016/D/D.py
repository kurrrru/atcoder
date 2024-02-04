def intersect(p1, p2, p3, p4):
    tc1 = (p1[0] - p2[0]) * (p3[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p3[0])
    tc2 = (p1[0] - p2[0]) * (p4[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p4[0])
    td1 = (p3[0] - p4[0]) * (p1[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p1[0])
    td2 = (p3[0] - p4[0]) * (p2[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p2[0])
    return tc1*tc2<0 and td1*td2<0

ax,ay,bx,by=map(int,input().split())
A=[ax,ay]
B=[bx,by]
N=int(input())
P=[[0,0] for _ in range(N)]
cnt=0
for i in range(N):
    P[i]=list(map(int,input().split()))
for i in range(N):
    if intersect(A,B,P[i],P[i-1]):
        cnt+=1
print(cnt//2+1)