from collections import deque
H,W=map(int,input().split())
S=[""]*H
used=[[False]*W for _ in range(H)]
for i in range(H):
    S[i]=list(input())
que=deque()

num_s=0
for i in range(H):
    for j in range(W):
        if used[i][j]: continue
        if S[i][j] != "#": continue
        used[i][j]=True
        que.append((i,j))
        num_s+=1
        while que:
            s,t=que.popleft()
            for ds in range(-1,2):
                for dt in range(-1,2):
                    if ds==0 and dt==0:
                        continue
                    if not (0<=s+ds<H and 0<=t+dt<W):
                        continue
                    if used[s+ds][t+dt] or S[s+ds][t+dt]!="#":
                        continue
                    used[s+ds][t+dt]=True
                    que.append((s+ds,t+dt))
print(num_s)