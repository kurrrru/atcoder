from subprocess import call
from os import chdir
for c in "ABCDEFG":
    with open(f"./{c}/{c}.py", "w", encoding="utf-8"):
        pass
    chdir(f"./{c}")
    call(f"oj d https://atcoder.jp/contests/abc323/tasks/abc323_{c.lower()}",shell=True)
    chdir("..")