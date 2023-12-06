p,q = input().split()
al=list("ABCDEFG")
p=al.index(p)
q=al.index(q)
dist=[0,3,4,8,9,14,23]
print(abs(dist[q]-dist[p]))