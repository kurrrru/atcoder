# 敵をpriority_queueで管理(弱いものから倒す)
# 薬はsort済みリストで管理(二分探索でぎりぎりを探す)
# ...できてない
# dpらしい




N=int(input())
p=[0]*N
t=[0]*N
s=[0]*N
g=[0]*N
c=[[] for _ in range(N)]

import queue
que1=queue.PriorityQueue(N)
que2=queue.PriorityQueue(N)


for i in range(1,N-1):
    p[i],t[i],s[i],g[i]=map(int,input().split())
    p[i]-=1
    c[p[i]].append(i)
    if t[i]==1 and p[i]==0:
        que1.put((s[i],i))
    elif p[i]==0:
        que2.put((g[i],i))
h=1
used=[False]*N
while not (que1.empty() and que2.empty()):
    print(que1.queue,que2.queue)
    if que1.empty():
        S,i=que2.get()
        used[i]=True
        for j in range(len(c[i])):
            if used[j]: continue
            if t[j]==1:
                que1.put((s[j],j))
            else:
                que2.put((g[j],j))
        h*=g[i]
        continue
    S,i=que1.get()
    if h>S:
        h+=g[i]
        used[i]=True
        for j in range(len(c[i])):
            if used[j]: continue
            if t[j]==1:
                que1.put((s[j],j))
            else:
                que2.put((g[j],j))
        continue
    else:
        que1.put((S,i))
        if que2.empty():
            print("No")
            exit()
        S,i=que2.get()
        h*=g[i]
        used[i]=True
        for j in range(len(c[i])):
            if used[i]: continue
            if t[j]==1:
                que1.put((s[j],j))
            else:
                que2.put((g[j],j))
        continue
print("Yes")