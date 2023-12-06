T=int(input())
def mul(m,l):
    for i in range(len(l)):
        l[i]*=m
    return l

def make_list(N,m):
    if N==1: return mul(m,[1])
    if N==2: return []
    if N==3: return mul(m,[2,3,6])
    if N==4: return mul(m,[2,3,10,15])
    if N==5: return mul(m,[2,5,6,10,30])
    if N==6: return mul(m,[3,4,6,8,12,24]) # 2(2, 2(2,3,6)),3,6
    if N==7: return mul(m,[2,6,8,12,16,24,48])
    if N==8: return mul(m,[2,4,10,12,15,20,30,60])
    if N==9: return mul(m,[3,4,6,10,12,15,20,30,60])
    
    