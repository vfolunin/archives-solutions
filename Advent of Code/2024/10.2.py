from sys import stdin


def dfs(a, y, x):
    if a[y][x] == '9':
        return 1

    res = 0
    for dy, dx in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
        ty, tx = y + dy, x + dx
        if 0 <= ty < len(a) and 0 <= tx < len(a[0]) and int(a[y][x]) + 1 == int(a[ty][tx]):
            res += dfs(a, ty, tx)
    return res


a = [line.strip() for line in stdin]

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == '0':
            res += dfs(a, y, x)

print(res)