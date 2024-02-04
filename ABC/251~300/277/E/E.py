class queue:
    tail = 0
    head = 0
    q = []
    length = 0
    n = 0
    def __init__(self, n = 100):
        self.q = [0 for _ in range(n)]
        self.length = n
    def enqueue(self, x):
        self.n += 1
        self.q[self.tail] = x
        if self.tail == self.length - 1:
            self.tail = 0
        else:
            self.tail = self.tail + 1
    
    def dequeue(self):
        self.n -= 1
        x = self.q[self.head]
        self.q[self.head] = 0
        if self.head == self.length - 1:
            self.head = 0
        else:
            self.head = self.head + 1
        return x

n, m, k = map(int, input().split())
u = [0 for _ in range(m)]
v = [0 for _ in range(m)]
a = [0 for _ in range(m)]

l = {}
for i in range(m):
    u[i], v[i], a[i] = map(lambda x: int(x) - 1, input().split())
    if u[i] in l:
        l[u[i]].append([v[i], a[i]+1])
    else:
        l[u[i]] = [[v[i], a[i]+1]]
    if v[i] in l:
        l[v[i]].append([u[i], a[i]+1])
    else:
        l[v[i]] = [[u[i], a[i]+1]]
S = list(map(lambda x: int(x) - 1, input().split()))
s = [0 for i in range(n)]
for i in range(len(S)):
    s[S[i]] = 1

f = [[False, False] for _ in range(n)]
# [now, time, state]を記録しながら幅優先
q = queue(m+2)
q.enqueue([0, 0, 1])
f[0][1] = True
while q.n > 0:
    tmpL = q.dequeue()
    now = tmpL[0]
    time = tmpL[1]
    state = tmpL[2]
    if now == n - 1:
        print(time)
        break
    if s[now] == 1:
        state = 1 - state
    for L2 in l[now]:
        if L2[1] == state:
            if f[L2[0]][L2[1]] == False:
                q.enqueue([L2[0], time + 1, state])
                f[L2[0]][L2[1]] = True
            
else:
    print(-1)
# n-1に達したら終了