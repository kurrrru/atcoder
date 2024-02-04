def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(n**0.5)+3):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])
    return arr

MOD=998244353

A,B=map(int,input().split())
d=1
arr=factorization(A)

odd_flag=B&1
for i in range(len(arr)):
    odd_flag&=(arr[i][1]&1==0)
    d*=(arr[i][1]*B+1)
    d%=MOD
print((d*B-odd_flag)*pow(2,-1,MOD)%MOD)
    