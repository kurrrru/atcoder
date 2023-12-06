q = int(input())
s = ["1"]*600000
j = 1
i = 0
ans = 1
MOD = 998244353

t = [1] * 600000
for k in range(600000-1):
    t[k+1] = (t[k] * 10) % MOD 
    

for _ in range(q):
    a = input().split()
    if a[0] == "1":
        s[j] = a[1]
        ans = (ans * 10 + int(a[1])) % MOD
        j += 1
    elif a[0] == "2":
        ans = (ans - t[j-i-1]*int(s[i])) % MOD
        i += 1
    else:
        print(ans)