from heapq import heappush, heappop
from sys import stdin


def dijkstra(a):
    n, size = len(a), len(a) * 5
    dist = [[1e9 for x in range(size)] for y in range(size)]
    q = []

    dist[0][0] = 0
    heappush(q, [0, 0, 0])

    while len(q):
        y, x, d = heappop(q)
        if dist[y][x] != d:
            continue

        for dy, dx in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            ty, tx = y + dy, x + dx
            w = a[ty % n][tx % n] + ty // n + tx // n
            if w > 9:
                w -= 9
            if 0 <= ty < size and 0 <= tx < size and \
                    dist[ty][tx] > dist[y][x] + w:
                dist[ty][tx] = dist[y][x] + w
                heappush(q, [ty, tx, dist[ty][tx]])

    return dist[-1][-1]


a = [[int(c) for c in line.strip()] for line in stdin]
print(dijkstra(a))
