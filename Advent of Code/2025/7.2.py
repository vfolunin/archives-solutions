from collections import defaultdict
from sys import stdin

ways = defaultdict(int)
for line in stdin:
    for x in range(len(line)):
        if line[x] == 'S':
            ways[x] = 1
        elif line[x] == '^' and x in ways:
            ways[x - 1] += ways[x]
            ways[x + 1] += ways[x]
            del ways[x]

print(sum(ways.values()))
