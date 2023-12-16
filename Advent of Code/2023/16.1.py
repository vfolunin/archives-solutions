from collections import deque
from sys import stdin

a = [list(line.strip()) for line in stdin]
h, w = len(a), len(a[0])

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

seen = set()
res = set()
q = deque()

seen.add((0, 0, 1))
res.add((0, 0))
q.append((0, 0, 1))

while q:
    y, x, d = q.popleft()
    tds = []

    if d in [0, 2] and a[y][x] == '-' or d in [1, 3] and a[y][x] == '|':
        tds.append((d - 1) % len(dy))
        tds.append((d + 1) % len(dy))
    elif a[y][x] == '/':
        tds.append(d ^ 1)
    elif a[y][x] == '\\':
        tds.append(3 - d)
    else:
        tds.append(d)

    for td in tds:
        ty = y + dy[td]
        tx = x + dx[td]

        if 0 <= ty < h and 0 <= tx < w and (ty, tx, td) not in seen:
            seen.add((ty, tx, td))
            res.add((ty, tx))
            q.append((ty, tx, td))

print(len(res))
