# ABC310 C
N=int(input())
S=set()
for i in range(N):
    A=input()
    S.add(min(A,A[::-1]))
print(len(S))