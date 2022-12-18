from sys import stdin

points = set()
for line in stdin:
    points.add(tuple(int(_) for _ in line.strip().split(',')))

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

res = 0
for x, y, z in points:
    for d in range(len(dx)):
        res += (x + dx[d], y + dy[d], z + dz[d]) not in points

print(res)
