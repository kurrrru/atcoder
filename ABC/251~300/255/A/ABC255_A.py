r,c = map(int, input().split())
a = [[0,0],[0,0]]
a[0] = list(map(int,input().split()))
a[1] = list(map(int,input().split()))
print(a[r-1][c-1])