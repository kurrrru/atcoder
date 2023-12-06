n, a, b = map(int, input().split())
x = list(map(int, input().split()))
fatigue = 0
for i in range(1, n):
    fatigue += min((x[i] - x[i-1]) * a, b)
print(fatigue)