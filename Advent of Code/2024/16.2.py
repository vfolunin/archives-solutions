from heapq import heappush, heappop
from sys import stdin

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def dijkstra(a, y, x, d, backward=False):
    dist = {}
    q = []
    dist[(y, x, d)] = 0
    heappush(q, (dist[(y, x, d)], y, x, d))

    while q:
        cur_dist, y, x, d = heappop(q)
        if cur_dist != dist[(y, x, d)]:
            continue

        for ty, tx, td, weight in [(y + dy[d] * (-1 if backward else 1), x + dx[d] * (-1 if backward else 1), d, 1),
                                   (y, x, (d + 1) % len(dy), 1000),
                                   (y, x, (d - 1) % len(dy), 1000)]:
            if a[ty][tx] != '#' and ((ty, tx, td) not in dist or dist[(ty, tx, td)] > dist[(y, x, d)] + weight):
                dist[(ty, tx, td)] = dist[(y, x, d)] + weight
                heappush(q, (dist[(ty, tx, td)], ty, tx, td))

    return dist


def get_min_dist_start(dist_start, y, x):
    res = 10 ** 9
    for d in range(len(dy)):
        if (y, x, d) in dist_start:
            res = min(res, dist_start[(y, x, d)])
    return res


a = [line.strip() for line in stdin]

dist_start = dijkstra(a, len(a) - 2, 1, 1)
dist = get_min_dist_start(dist_start, 1, len(a[0]) - 2)
dist_finish = [dijkstra(a, 1, len(a[0]) - 2, d, backward=True) for d in range(len(dy))]

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == '#':
            continue

        ok = 0
        for d in range(len(dy)):
            if (y, x, d) in dist_start:
                for fd in range(len(dy)):
                    if (y, x, d) in dist_finish[fd] and dist_start[(y, x, d)] + dist_finish[fd][(y, x, d)] == dist:
                        ok = 1
        res += ok

print(res)