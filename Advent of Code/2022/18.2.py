from collections import deque
from sys import stdin

points = set()
for line in stdin:
    points.add(tuple(int(_) for _ in line.strip().split(',')))

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

q = deque()
visited = set()

q.append((0, 0, 0))
visited.add((0, 0, 0))

res = 0
while q:
    x, y, z = q.popleft()
    for d in range(len(dx)):
        tx, ty, tz = x + dx[d], y + dy[d], z + dz[d]
        if (tx, ty, tz) in points:
            res += 1
        elif -1 <= tx <= 20 and -1 <= ty <= 20 and -1 <= tz <= 20 and (tx, ty, tz) not in visited:
            q.append((tx, ty, tz))
            visited.add((tx, ty, tz))

print(res)
