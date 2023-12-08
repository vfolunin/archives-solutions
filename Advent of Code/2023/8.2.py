from collections import defaultdict
from math import lcm
from sys import stdin

lines = [line.strip() for line in stdin]

graph = defaultdict(dict)
for line in lines[2:]:
    v, to = line.split(' = ')
    to_l, to_r = to[1:-1].split(', ')
    graph[v]['L'] = to_l
    graph[v]['R'] = to_r

res = 1
for name in graph:
    if name[-1] == 'A':
        v, i = name, 0
        while v[-1] != 'Z':
            v = graph[v][lines[0][i % len(lines[0])]]
            i += 1
        res = lcm(res, i)
print(res)
