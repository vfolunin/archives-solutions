from sys import stdin

a = [line.strip() for line in stdin]

for y in range(len(a)):
    if '^' in a[y]:
        x = a[y].index('^')
        break
d = 0

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

visited = set()
while 0 <= y < len(a) and 0 <= x < len(a[0]):
    visited.add((y, x))

    while 1:
        ty = y + dy[d]
        tx = x + dx[d]
        if ty < 0 or ty >= len(a) or tx < 0 or tx >= len(a[0]) or a[ty][tx] != '#':
            break
        d = (d + 1) % len(dy)

    y = ty
    x = tx

print(len(visited))
