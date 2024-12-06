import sys
from sys import stdin


def loop(a, y, x, d):
    visited = set()
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    while 0 <= y < len(a) and 0 <= x < len(a[0]) and (y, x, d) not in visited:
        visited.add((y, x, d))

        while 1:
            ty = y + dy[d]
            tx = x + dx[d]
            if ty < 0 or ty >= len(a) or tx < 0 or tx >= len(a[0]) or a[ty][tx] != '#':
                break
            d = (d + 1) % len(dy)

        y = ty
        x = tx

    return (y, x, d) in visited


a = [list(line.strip()) for line in stdin]

for sy in range(len(a)):
    if '^' in a[sy]:
        sx = a[sy].index('^')
        break

res = 0
for y in range(len(a)):
    print(y, file=sys.stderr)
    for x in range(len(a[0])):
        if a[y][x] != '#':
            a[y][x] = '#'
            res += loop(a, sy, sx, 0)
            a[y][x] = '.'

print(res)
