N=input()
for i in range(len(N)-1):
    if N[i]<=N[i+1]:
        print("No")
        break
else:
    print("Yes")
