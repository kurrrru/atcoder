from subprocess import call
print("generate start")
call("pypy gn_run.py",shell=True)
print("generate end")
print("judge start")
call("pypy judge.py",shell=True)
print("judge end")