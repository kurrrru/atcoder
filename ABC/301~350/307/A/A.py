N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    print(sum(A[i*7:i*7+7]), end=" ")
print("")