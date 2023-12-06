R,G,B=map(int,input().split())
ans=0
s=lambda x:x*(x+1)//2
f1=lambda x:s(x//2)+s(x-x//2-1)


if R+G<=200 and G+B<=200:
    ans=f1(R)+f1(G)+f1(B)
else:
    m=1<<20
    for a in range(-600,300):
        tmp=0
        if a<=-100:
            tmp+=s(-100-a+R)-s(-100-a)
        elif a<-100+R//2:
            tmp+=s(a+99)+s(R-a-100)
        else:
            tmp+=f1(R)
        if a<-G:
            tmp+=s(-a)-s(-a-G)
        elif a>0:
            tmp+=s(a+G-1)-s(a-1)
        else:
            tmp+=s(-a)+s(G+a-1)
        if a+G>100:
            tmp+=s(a+G+B-101)-s(a+G-101)
        elif a+G>100-B//2:
            tmp+=s(100-a-G)+s(B-101+a+G)
        else:
            tmp+=f1(B)
        m=min(m,tmp)
    ans=m
print(ans)
            
