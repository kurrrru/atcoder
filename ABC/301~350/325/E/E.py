import heapq
class Dijkstra:
    def __init__(self, num_node):
        self.num_node = num_node
        self.edge = [float("inf")] * (num_node * num_node)
    def add_edge(self, start, end, cost):
        self.edge[start * self.num_node + end]=cost
    def delete_edge(self, start, end):
        self.edge[start * self.num_node + end]=float("inf")
    def dijkstra(self, start):
        "startからの最短距離を求める。"
        self.start = start
        self.d = [float("inf")] * self.num_node
        c = [start] # 0*N + start
        used = [False] * self.num_node
        while c:
            w, u = divmod(heapq.heappop(c), self.num_node)
            if used[u]: continue
            self.d[u] = w
            used[u] = True
            for v in range(self.num_node):
                if used[v]: continue
                if self.d[v] > self.d[u] + self.edge[u * self.num_node + v]:
                    self.d[v] = self.d[u] + self.edge[u * self.num_node + v]
                    heapq.heappush(c, self.d[v] * self.num_node + v)
        return self.d   


N,A,B,C=map(int,input().split())
graph = Dijkstra(2*N)
for i in range(N):
    d=list(map(int,input().split()))
    for j in range(N):
        graph.add_edge(i,j,A*d[j])
        graph.add_edge(i,j+N,A*d[j])
        graph.add_edge(i+N,j+N,B*d[j]+C)
d=graph.dijkstra(0)
print(min(d[N-1],d[2*N-1]))