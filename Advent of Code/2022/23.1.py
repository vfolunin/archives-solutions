from collections import defaultdict
from sys import stdin

coords = set()
for y, line in enumerate(stdin):
    for x in range(len(line)):
        if line[x] == '#':
            coords.add((y, x))

dy = [-1, -1, -1, 1, 1, 1, -1, 0, 1, -1, 0, 1]
dx = [-1, 0, 1, -1, 0, 1, -1, -1, -1, 1, 1, 1]
d = 0

for round in range(10):
    claims = defaultdict(int)
    to = {}

    for y, x in coords:
        neighbor_count = 0
        for ty in range(y - 1, y + 2):
            for tx in range(x - 1, x + 2):
                neighbor_count += (ty, tx) in coords
        if neighbor_count == 1:
            continue

        for i in range(4):
            ok = 1
            for j in range(3):
                ty, tx = y + dy[(d + 3 * i + j) % len(dy)], x + dx[(d + 3 * i + j) % len(dy)]
                ok &= (ty, tx) not in coords
            if ok:
                ty, tx = y + dy[(d + 3 * i + 1) % len(dy)], x + dx[(d + 3 * i + 1) % len(dy)]
                claims[(ty, tx)] += 1
                to[(y, x)] = (ty, tx)
                break

    next_coords = set()
    for y, x in coords:
        if (y, x) in to and claims[to[(y, x)]] == 1:
            next_coords.add(to[(y, x)])
        else:
            next_coords.add((y, x))

    coords = next_coords
    d = (d + 3) % len(dy)

min_y = min(y for (y, x) in coords)
max_y = max(y for (y, x) in coords)
min_x = min(x for (y, x) in coords)
max_x = max(x for (y, x) in coords)
print((max_y - min_y + 1) * (max_x - min_x + 1) - len(coords))
