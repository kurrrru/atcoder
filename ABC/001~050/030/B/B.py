N,M=map(int,input().split())
print(abs((N%12)*30-M*5.5)%360)