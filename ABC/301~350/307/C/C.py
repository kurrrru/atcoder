HA, WA = map(int, input().split())
A = []
for i in range(HA):
    A.append(input())

HB, WB = map(int, input().split())
B = []
for i in range(HB):
    B.append(input())
    
HX, WX = map(int, input().split())
X = []
for i in range(HX):
    X.append(input())

def add(s1,s2):
    if s1 == "#" or s2 == "#":
        return "#"
    return "."

for s in range(40):
    for t in range(40):
        C = [["."]*50 for _ in range(50)]
        for i in range(HA):
            for j in range(WA):
                C[i+20][j+20]=add(C[i+20][j+20],A[i][j])
        for i in range(HB):
            for j in range(WB):
                C[i+s][j+t]=add(C[i+s][j+t],B[i][j])
        for d1 in range(40):
            for d2 in range(40):
                for i in range(HX):
                    for j in range(WX):
                        if C[d1+i][d2+j]!=X[i][j]:
                            break
                    else:
                        continue
                    break
                else:
                    for u in range(50):
                        for v in range(50):
                            if not (d1<=u<d1+HX and d2<=v<d2+WX) and C[u][v]=="#":
                                break
                        else:
                            continue
                        break
                    else:
                        print("Yes")
                        exit()
print("No")
                        
 

