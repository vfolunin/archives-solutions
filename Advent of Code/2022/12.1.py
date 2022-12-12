from sys import stdin
from collections import deque


a = [list(line.strip()) for line in stdin]
h, w = len(a), len(a[0])

for y in range(h):
    for x in range(w):
        if a[y][x] == 'S':
            start_y, start_x = y, x
            a[y][x] = 'a'
        elif a[y][x] == 'E':
            finish_y, finish_x = y, x
            a[y][x] = 'z'

dist = [[10 ** 9 for x in range(w)] for y in range(h)]
q = deque()

dist[start_y][start_x] = 0
q.append((start_y, start_x))

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

while q:
    y, x = q.popleft()
    for d in range(len(dy)):
        ty, tx = y + dy[d], x + dx[d]
        if 0 <= ty < h and 0 <= tx < w and dist[ty][tx] == 10 ** 9 and ord(a[ty][tx]) - ord(a[y][x]) <= 1:
            dist[ty][tx] = dist[y][x] + 1
            q.append((ty, tx))

print(dist[finish_y][finish_x])
