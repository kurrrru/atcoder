from subprocess import call
class bcolors:
    OK = '\033[92m' #GREEN
    WARNING = '\033[93m' #YELLOW
    FAIL = '\033[91m' #RED
    RESET = '\033[0m' #RESET COLOR
start=1
end=500
N=50
M=100
def neighboring(C):
    neighbor=[set() for _ in range(M+1)]
    for i in range(N):
        for j in range(N):
            if i==0 or j==0 or i==N-1 or j==N-1:
                neighbor[0].add(C[i][j])
                neighbor[C[i][j]].add(0)
            if i<N-1 and C[i][j]!=C[i+1][j]:
                neighbor[C[i][j]].add(C[i+1][j])
                neighbor[C[i+1][j]].add(C[i][j])
            if j<N-1 and C[i][j]!=C[i][j+1]:
                neighbor[C[i][j]].add(C[i][j+1])
                neighbor[C[i][j+1]].add(C[i][j])
    neighbor[0].discard(0)
    return neighbor
def is_OK_1(D):
    for i in range(N):
        for j in range(N):
            if D[i][j]!=0:
                continue #OK
            if i==0 or i==N-1 or j==0 or j==N-1:
                continue #OK
            for di,dj in [(0,1),(0,-1),(1,0),(-1,0)]:
                if D[i+di][j+dj]==0:
                    break #OK
            else:
                return False
    return True

def is_OK_2(C,D):
    neC=neighboring(C)
    neD=neighboring(D)
    return neC==neD

suc=0
fai=0
for case_num in range(start,end+1):
    call(f"cat ./test/sample{case_num}.in | pypy solve.py > output/output{case_num}.out",shell=True)
    with open(f"./test/sample{case_num}.in") as testcase:
        N,M=map(int,testcase.readline().split())
        C=[[0 for _ in range(N)] for _ in range(N)]
        for i in range(N):
            C[i]=list(map(int,testcase.readline().split()))
    with open(f"./output/output{case_num}.out") as output:
        D=[[0 for _ in range(N)] for _ in range(N)]
        for i in range(N):
            D[i]=list(map(int,output.readline().split()))
    
    if is_OK_1(D) and is_OK_2(C,D):
        print(f"case{case_num:2}: {bcolors.OK}[success]{bcolors.RESET}")
        suc+=1
    elif is_OK_1(D):
        print(f"case{case_num:2}: {bcolors.FAIL}[failure]{bcolors.RESET} not satisfied 'is_OK_2'")
        fai+=1
    else:
        print(f"case{case_num:2}: {bcolors.FAIL}[failure]{bcolors.RESET} not satisfied 'is_OK_1'")
        fai+=1
print(f"success:{suc}\nfailure:{fai}")
        
    
    
    