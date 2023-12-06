def Merge(A, B, p, q, r):
    INF = max(A)+1 
    n1 = q-p+1
    n2 = r-q
    L = [0] * (n1+1)
    R = [0] * (n2+1)
    Lb = [0] * (n1+1)
    Rb = [0] * (n2+1)
    
    for i in range(n1):
        L[i] = A[p+i]
        Lb[i] = B[p+i]
    for j in range(n2):
        R[j] = A[q+j+1]
        Rb[j] = B[q+j+1]
    L[n1] = INF
    R[n2] = INF
    i = 0
    j = 0
    for k in range(p, r+1):
        if L[i] <= R[j]:
            A[k] = L[i]
            B[k] = Lb[i]
            i += 1
        else:
            A[k] = R[j]
            B[k] = Rb[j]
            j += 1
    return A

# --- マージソート(再帰) ---
def MergeSort_sub(A, B, p, r):
    if p < r:
        q = (p+r) // 2
        MergeSort_sub(A, B, p, q)
        MergeSort_sub(A, B, q+1, r)
        Merge(A,B,p,q,r)
    return A

# --- マージソート ---
def MergeSort(A, B):#Aについてソート
    MergeSort_sub(A, B, 0, len(A)-1)
    return A

n=int(input())
s=[""]*n
count_x=[0]*n
sum_num=[0]*n
self_point=[0]*n
for i in range(n):
    s[i]=input()
    for j in range(len(s[i])):
        if s[i][j]=='X':
            count_x[i]+=1
        else:
            sum_num[i]+=int(s[i][j])
            self_point[i]+=count_x[i]*int(s[i][j])
inf_point=sum(self_point)
MergeSort(sum_num,count_x)
sum_x=[0]*n
sum_x[0]=count_x[0]
for i in range(1,n):
    sum_x[i]=sum_x[i-1]+count_x[i]
for i in range(1,n):
    inf_point+=sum_num[i]*sum_x[i]
print(inf_point)            
    