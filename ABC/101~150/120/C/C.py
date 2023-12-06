#120-C
S=input()
N=len(S)
cnt=0
v=0
for i in range(N):
    if S[i]=="0":
        if v<0:
            cnt+=1
        v+=1
    else:
        if v>0:
            cnt+=1
        v-=1
print(cnt*2)    