from collections import deque
from sys import stdin


def bfs(a, start_y, start_x):
    dist = [[10 ** 9 for x in range(len(a[0]))] for y in range(len(a))]
    q = deque()
    res = 0

    dist[start_y][start_x] = 0
    q.append([start_y, start_x])

    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    ds = {'|': [0, 2], '-': [1, 3], 'L': [0, 1], 'F': [1, 2], '7': [2, 3], 'J': [0, 3]}

    while len(q):
        y, x = q.popleft()

        for d in ds[a[y][x]]:
            ty = y + dy[d]
            tx = x + dx[d]

            if 0 <= ty < len(a) and 0 <= tx < len(a[0]) and dist[ty][tx] == 10 ** 9:
                dist[ty][tx] = dist[y][x] + 1
                q.append([ty, tx])
                res = max(res, dist[ty][tx])

    return res


a = [list(line.strip()) for line in stdin]

for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == 'S':
            start = [y, x]
            a[y][x] = 'F'

print(bfs(a, *start))
