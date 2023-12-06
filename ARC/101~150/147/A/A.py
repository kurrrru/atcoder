n=int(input())
a=list(map(int,input().split()))
a.sort()
mini=0
maxi=n-1
cnt=0
while maxi!=mini:
    a[maxi]%=a[mini]
    if a[maxi]>0:
        mini=maxi
    maxi=(maxi+n-1)%n
    while a[maxi]==0:
        maxi=(maxi+n-1)%n
    cnt+=1
print(cnt)