from collections import defaultdict
from sys import stdin

a = [line.strip() for line in stdin]

cells = defaultdict(set)
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] != '.':
            cells[a[y][x]].add((y, x))

res = set()
for cells in cells.values():
    for y1, x1 in cells:
        for y2, x2 in cells:
            if y1 == y2 and x1 == x2:
                continue
            for step in range(100):
                y = y2 + (y2 - y1) * step
                x = x2 + (x2 - x1) * step
                if 0 <= y < len(a) and 0 <= x < len(a[0]):
                    res.add((y, x))
                else:
                    break

print(len(res))