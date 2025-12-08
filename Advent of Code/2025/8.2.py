from math import prod
from sys import stdin


class DSU:
    def __init__(self, size):
        self.parent = list(range(size))
        self.size = [1] * len(self.parent)

    def find(self, v):
        if self.parent[v] == v:
            return v
        self.parent[v] = self.find(self.parent[v])
        return self.parent[v]

    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def merge(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        if ra == rb:
            return
        if self.size[ra] > self.size[rb]:
            self.parent[rb] = ra
            self.size[ra] += self.size[rb]
        else:
            self.parent[ra] = rb
            self.size[rb] += self.size[ra]


def get_dist(a, b):
    sum = 0
    for i in range(len(a)):
        sum += (a[i] - b[i]) ** 2
    return sum ** 0.5


points = [[int(_) for _ in line.strip().split(',')] for line in stdin]

edges = []
for a in range(len(points)):
    for b in range(a + 1, len(points)):
        edges.append([get_dist(points[a], points[b]), a, b])
edges.sort()

dsu = DSU(1000)
res = 0
for _, a, b in edges:
    if not dsu.connected(a, b):
        res = points[a][0] * points[b][0]
        dsu.merge(a, b)

print(res)
