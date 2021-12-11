from sys import stdin


def dfs(a, y, x, flashed):
    flashed[y][x] = 1
    a[y][x] = 0
    flash_count = 1

    for dy, dx in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]:
        ty, tx = y + dy, x + dx
        if 0 <= ty < len(a) and 0 <= tx < len(a) and not flashed[ty][tx]:
            a[ty][tx] += 1
            if a[ty][tx] > 9:
                flash_count += dfs(a, ty, tx, flashed)

    return flash_count


def step(a):
    for y in range(len(a)):
        for x in range(len(a)):
            a[y][x] += 1

    flashed = [[0 for x in range(len(a))] for y in range(len(a))]
    flash_count = 0

    for y in range(len(a)):
        for x in range(len(a)):
            if a[y][x] > 9:
                flash_count += dfs(a, y, x, flashed)

    return flash_count


a = [[int(c) for c in line.strip()] for line in stdin]

timer = 1
while step(a) != len(a) ** 2:
    timer += 1
print(timer)
