from heapq import heappush, heappop
from sys import stdin


def dijkstra(a):
    dist = [[1e9 for x in range(len(a))] for y in range(len(a))]
    q = []

    dist[0][0] = 0
    heappush(q, [0, 0, 0])

    while len(q):
        y, x, d = heappop(q)
        if dist[y][x] != d:
            continue

        for dy, dx in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            ty, tx = y + dy, x + dx
            if 0 <= ty < len(a) and 0 <= tx < len(a) and \
                    dist[ty][tx] > dist[y][x] + a[ty][tx]:
                dist[ty][tx] = dist[y][x] + a[ty][tx]
                heappush(q, [ty, tx, dist[ty][tx]])

    return dist[-1][-1]


a = [[int(c) for c in line.strip()] for line in stdin]
print(dijkstra(a))
