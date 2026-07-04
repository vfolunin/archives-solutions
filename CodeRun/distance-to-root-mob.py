from collections import deque


def bfs(graph, root):
    dist = [1e9 for v in range(len(graph))]
    q = deque()

    dist[root] = 0
    q.append(root)

    while q:
        v = q.popleft()
        for to in graph[v]:
            dist[to] = dist[v] + 1
            q.append(to)

    return dist


vertex_count = int(input())
parent = [int(_) - 1 for _ in input().split()]

graph = [[] for v in range(vertex_count)]
root = -1
for v in range(vertex_count):
    if parent[v] == -1:
        root = v
    else:
        graph[parent[v]].append(v)

print(*bfs(graph, root))