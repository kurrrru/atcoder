
c0=list(map(int,input().split()))
c1=list(map(int,input().split()))
c2=list(map(int,input().split()))
c=c0+c1+c2

cnt=0
MAX_N=9
used=[False]*MAX_N
perm=[-1]*MAX_N 
tocheck=[
    [0,3,6],
    [0,4,],
    [0,5,7],
    [1,3,],
    [1,4,6,7],
    [1,5,],
    [2,3,7],
    [2,4,],
    [2,5,6],
]

def gakkari():
    found=[[] for _ in range(8)]
    # print(found)
    for i in range(9):
        # print(found)
        for j in range(len(tocheck[perm[i]])):
            # print(f"tocheck[{perm[i]}][{j}]={tocheck[perm[i]][j]}")
            if len(found[tocheck[perm[i]][j]])==0:
                found[tocheck[perm[i]][j]].append(c[perm[i]])
            elif len(found[tocheck[perm[i]][j]])==1:
                if found[tocheck[perm[i]][j]][0]==c[perm[i]]:
                    return True
                else:
                    found[tocheck[perm[i]][j]].append(c[perm[i]])
            else:
                found[tocheck[perm[i]][j]].append(c[perm[i]])
                
    return False
            
def permutation(pos, n):
    global perm, used, cnt
    # permの中に順列を生成する
    if pos == n:
        if gakkari():
            cnt+=1
        return
    
    for i in range(n):
        if not used[i]:
            perm[pos] = i
            used[i] = True
            permutation(pos+1, n)
            used[i]=False
    return
permutation(0,9)
print(1-(cnt/362880))
# print(cnt)
# perm=[6,1,0,2,3,4,5,7,8]
# print(gakkari())