from collections import defaultdict
from sys import stdin

lines = [line.strip() for line in stdin]

graph = defaultdict(dict)
for line in lines[2:]:
    v, to = line.split(' = ')
    to_l, to_r = to[1:-1].split(', ')
    graph[v]['L'] = to_l
    graph[v]['R'] = to_r

v = 'AAA'
res = 0
while v != 'ZZZ':
    v = graph[v][lines[0][res % len(lines[0])]]
    res += 1
print(res)
