from subprocess import call
start=1
end=30
for case in range(start,end+1):
    print(f"{case=}:")
    call(f".\\tools_x86_64-pc-windows-gnu\\vis.exe .\\test\\sample{case}.in .\\output\\output{case}.out",shell=True)
