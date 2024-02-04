from queue import PriorityQueue
N,M=map(int,input().split())

ans=[0]*N

que=PriorityQueue(N+3)
que2=PriorityQueue(N+3)

for i in range(N):
    que.put(i)
    
for _ in range(M):
    T,W,S=map(int,input().split())
    if not que2.empty():
        t,p=que2.get()
        while t<=T:
            que.put(p)
            if que2.empty():
                break
            t,p=que2.get()
        if t>T:
            que2.put((t,p))
    if que.empty():
        continue
    p=que.get()
    ans[p]+=W
    que2.put((T+S,p))
for i in range(N):
    print(ans[i])
    