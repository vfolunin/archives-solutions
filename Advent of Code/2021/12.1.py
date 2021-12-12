from collections import defaultdict
from sys import stdin


def rec(graph, v, visited):
    if v == 'end':
        return 1

    if v.islower():
        visited.add(v)

    res = 0
    for to in graph[v]:
        if to not in visited:
            res += rec(graph, to, visited)

    if v.islower():
        visited.remove(v)

    return res


graph = defaultdict(set)

for line in stdin:
    a, b = line.strip().split('-')
    graph[a].add(b)
    graph[b].add(a)

print(rec(graph, 'start', set()))
