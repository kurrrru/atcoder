from subprocess import call
start=1
end=500

class bcolors:
    OK = '\033[92m' #GREEN
    WARNING = '\033[93m' #YELLOW
    FAIL = '\033[91m' #RED
    RESET = '\033[0m' #RESET COLOR

for i in range(start,end+1):
    # call("$OutputEncoding = [Text.Encoding]::Default",shell=True)
    try: 
        call(f"pypy gn.py > ./test/sample{i}.in",shell=True)
        print(f"case{i:2}: {bcolors.OK}done!{bcolors.RESET}")
    except:
        print(f"case{i:2}: {bcolors.FAIL}fail{bcolors.RESET}")