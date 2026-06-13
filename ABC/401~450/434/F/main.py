class K(str):__lt__=lambda s,o:s+o<o+s
I=iter(open(0).read().split());next(I)
for n in I:
 n=int(n);s=sorted([next(I)for _ in' '*n],key=K);j="".join;a=j(s[:-2]+s[::-1][:2])
 print(a if n<3 else j(s)if any(x+y==y+x for x,y in zip(s,s[1:]))else min(a,j(s[:-3]+[s[-2],s[-3],s[-1]])))