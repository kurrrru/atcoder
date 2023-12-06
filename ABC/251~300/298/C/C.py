n = int(input())
q = int(input())

num = [set() for _ in range(200001)]
box = [[] for _ in range(n+1)]

for _ in range(q):
    x, *args = map(int, input().split())
    if x == 1:
        s, t = args[0], args[1]
        num[s].add(t)
        box[t].append(s)
    elif x == 2:
        t = args[0]
        print(" ".join(map(str, sorted(list(box[t])))))    
    else:
        s = args[0]
        print(" ".join(map(str, sorted(num[s]))))
        
