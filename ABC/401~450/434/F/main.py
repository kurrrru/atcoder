import sys
class K(str):__lt__=lambda s,o:s+o<o+s
I=iter(sys.stdin.read().split())
for _ in range(int(next(I))):
 n=int(next(I));s=sorted([next(I)for _ in' '*n],key=K);j="".join
 a=j(s[:-2]+[s[-1],s[-2]])
 if n<3:print(a)
 elif any(x+y==y+x for x,y in zip(s,s[1:])):print(j(s))
 else:print(min(a,j(s[:-3]+[s[-2],s[-3],s[-1]])))