from sys import stdin


rocks = set()

for line in stdin:
    points = [[int(_) for _ in part.split(',')] for part in line.strip().split(' -> ')]
    for i in range(len(points) - 1):
        ax, ay = points[i]
        bx, by = points[i + 1]
        while ax != bx or ay != by:
            rocks.add((ax, ay))
            if ax != bx:
                ax += 1 if ax < bx else -1
            if ay != by:
                ay += 1 if ay < by else -1
        rocks.add((bx, by))

res = 0
while True:
    x, y = 500, 0

    while y < 1000:
        if (x, y + 1) not in rocks:
            y += 1
        elif (x - 1, y + 1) not in rocks:
            x, y = x - 1, y + 1
        elif (x + 1, y + 1) not in rocks:
            x, y = x + 1, y + 1
        else:
            break

    if y == 1000:
        break

    rocks.add((x, y))
    res += 1

print(res)
