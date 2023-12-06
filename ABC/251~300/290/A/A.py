n,m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
print(sum([a[b[i] - 1] for i in range(len(b))]))