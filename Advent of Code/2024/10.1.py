from sys import stdin


def dfs(a, y, x, finishes):
    if a[y][x] == '9':
        finishes.add((y, x))
        return

    for dy, dx in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
        ty, tx = y + dy, x + dx
        if 0 <= ty < len(a) and 0 <= tx < len(a[0]) and int(a[y][x]) + 1 == int(a[ty][tx]):
            dfs(a, ty, tx, finishes)


a = [line.strip() for line in stdin]

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == '0':
            finishes = set()
            dfs(a, y, x, finishes)
            res += len(finishes)

print(res)