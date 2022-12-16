from collections import defaultdict
from re import findall
from sys import stdin


def read_graph():
    graph = defaultdict(list)
    bonus = {}
    for line in stdin:
        vertices = findall('([A-Z]{2})', line)
        bonus[vertices[0]] = int(findall('(\d+)', line)[0])
        for to in vertices[1:]:
            graph[vertices[0]].append(to)
    return graph, bonus


def get_dist(graph):
    dist = defaultdict(dict)
    for a in graph:
        for b in graph:
            dist[a][b] = 0 if a == b else 1e9

    for a in graph:
        for b in graph[a]:
            dist[a][b] = min(dist[a][b], 1)

    for v in graph:
        for a in graph:
            for b in graph:
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b])
    return dist


def rec(cur_time, cur_vertex, cur_bonus, bonus, dist, unvisited):
    if cur_time > 26:
        return -1e9

    res = cur_bonus * (26 - cur_time)

    for next_vertex in unvisited:
        next_time = cur_time + dist[cur_vertex][next_vertex] + 1
        next_bonus = cur_bonus + bonus[next_vertex]
        additional_bonus = cur_bonus * (next_time - cur_time)
        unvisited.remove(next_vertex)
        res = max(res, additional_bonus + rec(next_time, next_vertex, next_bonus, bonus, dist, unvisited))
        unvisited.add(next_vertex)

    return res


graph, bonus = read_graph()
dist = get_dist(graph)

vertices = [vertex for vertex in graph if bonus[vertex]]
res = 0
for mask in range(1 << len(vertices)):
    sets = [set(), set()]
    for bit in range(len(vertices)):
        sets[(mask >> bit) & 1].add(vertices[bit])
    res = max(res, rec(0, 'AA', 0, bonus, dist, sets[0]) + rec(0, 'AA', 0, bonus, dist, sets[1]))
    print(mask, res)
