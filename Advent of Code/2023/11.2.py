from heapq import heappush, heappop
from sys import stdin


def dijkstra(a, start_y, start_x):
    dist = [[10 ** 100 for x in range(len(a[0]))] for y in range(len(a))]
    q = []

    dist[start_y][start_x] = 0
    heappush(q, [dist[start_y][start_x], start_y, start_x])

    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    while len(q):
        cur_dist, y, x = heappop(q)
        if cur_dist != dist[y][x]:
            continue

        for d in range(len(dy)):
            ty = y + dy[d]
            tx = x + dx[d]
            weight = 10 ** 6 if a[y][x] == '*' else 1

            if 0 <= ty < len(a) and 0 <= tx < len(a[0]) and dist[ty][tx] > dist[y][x] + weight:
                dist[ty][tx] = dist[y][x] + weight
                heappush(q, [dist[ty][tx], ty, tx])

    return dist


a = [list(line.strip()) for line in stdin]

for i in range(2):
    for y in range(len(a) - 1, -1, -1):
        if '#' not in a[y]:
            a[y] = ['*' for x in range(len(a[y]))]
    a = [[a[y][x] for y in range(len(a))] for x in range(len(a[0]))]

cells = []
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == '#':
            cells.append([y, x])

res = 0
for i in range(len(cells)):
    dist = dijkstra(a, *cells[i])
    for j in range(i + 1, len(cells)):
        res += dist[cells[j][0]][cells[j][1]]
print(res)
