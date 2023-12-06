from itertools import count


def primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, n + 1):
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

n=int(input())
prime_list={}
if (n>1):
    prime_list=primes(int((n/2)**(1/3))+1)
numprime=len(prime_list)
c=0
f=0

memo=[0]*numprime
memo2=[0]*numprime
for i in range(numprime-1,-1,-1):
    q=prime_list[i]
    memo[i]=n//(q**3)
    #prime_listからmax_p以下の個数を数える
index=0
for i in range(numprime-1,-1,-1):
    while index<numprime and prime_list[i]<=memo[index]:
        if i < index:
            memo2[index]=i+1
        else:
            memo2[index]=index
        index+=1

for i in range(numprime):
    c+=memo2[i]

print(c)