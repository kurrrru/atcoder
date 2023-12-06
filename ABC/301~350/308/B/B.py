N,M=map(int,input().split())
C=input().split()
dic={}
D=[""]+input().split()
P=list(map(int,input().split()))
for i in range(M+1):
    dic[D[i]]=P[i]
cost=0
for i in range(N):
    cost+=dic[C[i]] if C[i] in dic else P[0]
print(cost)