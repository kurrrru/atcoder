N,M=map(int, input().split())
MOD = 998244353

c = 0
for i in range(N-1):
    c += M * pow(M-1, N-1-i, MOD) * (-1) ** (i%2)
    c %= MOD

print(c)