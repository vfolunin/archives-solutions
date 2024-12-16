from heapq import heappush, heappop
from sys import stdin


def dijkstra(a):
    y = len(a) - 2
    x = 1
    d = 1

    dist = {}
    q = []
    dist[(y, x, d)] = 0
    heappush(q, (dist[(y, x, d)], y, x, d))

    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    while q:
        cur_dist, y, x, d = heappop(q)
        if cur_dist != dist[(y, x, d)]:
            continue

        if a[y][x] == 'E':
            return dist[(y, x, d)]

        for ty, tx, td, weight in [(y + dy[d], x + dx[d], d, 1),
                                   (y, x, (d + 1) % len(dy), 1000),
                                   (y, x, (d - 1) % len(dy), 1000)]:
            if a[ty][tx] != '#' and ((ty, tx, td) not in dist or dist[(ty, tx, td)] > dist[(y, x, d)] + weight):
                dist[(ty, tx, td)] = dist[(y, x, d)] + weight
                heappush(q, (dist[(ty, tx, td)], ty, tx, td))


a = [line.strip() for line in stdin]

print(dijkstra(a))