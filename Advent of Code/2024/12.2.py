from sys import stdin


def get(a, y, x):
    return a[y][x] if 0 <= y < len(a) and 0 <= x < len(a[0]) else ' '


def is_side(a, y, x, ty, tx):
    if get(a, y, x) == get(a, ty, tx):
        return 0
    if y == ty:
        return get(a, y, x) != get(a, y - 1, x) or get(a, y - 1, x) == get(a, y - 1, tx)
    else:
        return get(a, y, x) != get(a, y, x - 1) or get(a, y, x - 1) == get(a, ty, x - 1)


def dfs(a, y, x, visited):
    visited[y][x] = 1

    sides = 0
    area = 1

    for dy, dx in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
        ty, tx = y + dy, x + dx
        sides += is_side(a, y, x, ty, tx)
        if 0 <= ty < len(a) and 0 <= tx < len(a[0]) and a[y][x] == a[ty][tx] and not visited[ty][tx]:
            delta_sides, delta_area = dfs(a, ty, tx, visited)
            sides += delta_sides
            area += delta_area

    return sides, area


a = [line.strip() for line in stdin]
visited = [[0 for x in range(len(a[0]))] for y in range(len(a))]

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if not visited[y][x]:
            sides, area = dfs(a, y, x, visited)
            res += sides * area

print(res)