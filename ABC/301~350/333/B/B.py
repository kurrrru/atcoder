# AC
S=input()
T=input()
def f(x):
    A=abs("ABCDE".index(x[0])-"ABCDE".index(x[1]))
    return min(A,5-A)
if f(S)==f(T):
    print("Yes")
else:
    print("No")