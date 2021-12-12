from collections import defaultdict
from sys import stdin


def rec(graph, v, visited, visited2):
    if v == 'end':
        return 1

    if v.islower():
        if v not in visited:
            visited.add(v)
        else:
            visited2.add(v)

    res = 0
    for to in graph[v]:
        if not to.islower() or \
                to != 'start' and (to not in visited or not len(visited2)):
            res += rec(graph, to, visited, visited2)

    if v.islower():
        if v not in visited2:
            visited.remove(v)
        else:
            visited2.remove(v)

    return res


graph = defaultdict(set)

for line in stdin:
    a, b = line.strip().split('-')
    graph[a].add(b)
    graph[b].add(a)

print(rec(graph, 'start', set(), set()))
