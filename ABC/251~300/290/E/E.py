n = int(input())
a = list(map(int, input().split()))
s = 0
t = {}

allEdge = 0
for i in range(1,n+1):
    allEdge += (n+1-i) * (i//2)
for i in range(n):
    if a[i] not in t:
        t[a[i]] = [i]
    else:
        t[a[i]].append(i)
for x in t:
    l = 0
    r = len(t[x]) - 1
    while l < r:
        if t[x][l] + 1 < n - t[x][r]:
            s += (r - l) * (t[x][l] + 1)
            l = l + 1
        else:
            s += (r - l) * (n - t[x][r])
            r = r - 1
print(allEdge - s)
                   
    
    

        
    