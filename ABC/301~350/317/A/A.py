import bisect
N,H,X=map(int,input().split())
P=list(map(int,input().split()))
print(bisect.bisect_left(P,X-H)+1)