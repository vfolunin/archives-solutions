from sys import stdin


def can_move(a, y, x, dy, dx):
    ty, tx = y + dy, x + dx
    if a[ty][tx] == '#':
        return 0
    if a[ty][tx] == '.':
        return 1
    if dx:
        return can_move(a, ty, tx, dy, dx)
    if a[ty][tx] == '[':
        return can_move(a, ty, tx, dy, dx) and can_move(a, ty, tx + 1, dy, dx)
    else:
        return can_move(a, ty, tx, dy, dx) and can_move(a, ty, tx - 1, dy, dx)


def move(a, y, x, dy, dx):
    ty, tx = y + dy, x + dx
    if a[ty][tx] == '.':
        a[ty][tx], a[y][x] = a[y][x], a[ty][tx]
        return
    if dx:
        move(a, ty, tx, dy, dx)
        a[ty][tx], a[y][x] = a[y][x], a[ty][tx]
    elif a[ty][tx] == '[':
        move(a, ty, tx, dy, dx)
        a[ty][tx], a[y][x] = a[y][x], a[ty][tx]
        move(a, ty, tx + 1, dy, dx)
        a[ty][tx + 1], a[y][x] = a[y][x], a[ty][tx + 1]
    else:
        move(a, ty, tx, dy, dx)
        a[ty][tx], a[y][x] = a[y][x], a[ty][tx]
        move(a, ty, tx - 1, dy, dx)
        a[ty][tx - 1], a[y][x] = a[y][x], a[ty][tx - 1]


a = []
wide = {'#': ['#', '#'], '.': ['.', '.'], 'O': ['[', ']'], '@': ['@', '.']}
ops = ''

for line in stdin:
    line = line.strip()
    if '#' in line:
        a.append([])
        for c in line:
            a[-1].extend(wide[c])
    else:
        ops += line

for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == '@':
            cy = y
            cx = x
            break

d = {'^': [-1, 0], '>': [0, 1], 'v': [1, 0], '<': [0, -1]}
for op in ops:
    dy, dx = d[op]
    if can_move(a, cy, cx, dy, dx):
        move(a, cy, cx, dy, dx)
        cy += dy
        cx += dx

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == '[':
            res += y * 100 + x

print(res)