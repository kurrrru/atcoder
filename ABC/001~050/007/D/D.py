a,b=input().split()
if int(a)>int(b):
    a,b=b,a

def countsub(s):
    n=len(s)
    if int(s[0])>=5:
        ret=(int(s[0])-1)*pow(8,n-1)
    else:
        ret=(int(s[0]))*pow(8,n-1)
    return ret

def count(s):
    s=str(int(s)+1)
    n=len(s)
    notProhibited=-1
    for i in range(n):
        notProhibited+=countsub(s[i:])
        if int(s[i])==4 or int(s[i])==9:
            break
    return int(s)-notProhibited

print(count(b)-count(str(int(a)-1)))