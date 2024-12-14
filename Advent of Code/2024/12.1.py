from sys import stdin


def dfs(a, y, x, visited):
    visited[y][x] = 1

    perimeter = 0
    area = 1

    for dy, dx in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
        ty, tx = y + dy, x + dx
        if ty < 0 or ty >= len(a) or tx < 0 or tx >= len(a[0]) or a[y][x] != a[ty][tx]:
            perimeter += 1
        elif not visited[ty][tx]:
            delta_perimeter, delta_area = dfs(a, ty, tx, visited)
            perimeter += delta_perimeter
            area += delta_area

    return perimeter, area


a = [line.strip() for line in stdin]
visited = [[0 for x in range(len(a[0]))] for y in range(len(a))]

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if not visited[y][x]:
            perimeter, area = dfs(a, y, x, visited)
            res += perimeter * area

print(res)