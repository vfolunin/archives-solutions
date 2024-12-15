from sys import stdin

a = []
moves = ''

for line in stdin:
    line = line.strip()
    if '#' in line:
        a.append(list(line))
    else:
        moves += line

for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == '@':
            cy = y
            cx = x
            break

d = {'^': [-1, 0], '>': [0, 1], 'v': [1, 0], '<': [0, -1]}
for move in moves:
    dy, dx = d[move]
    step = 1
    while a[cy + dy * step][cx + dx * step] == 'O':
        step += 1
    if a[cy + dy * step][cx + dx * step] == '.':
        for i in range(step, 0, -1):
            a[cy + dy * i][cx + dx * i] = a[cy + dy * (i - 1)][cx + dx * (i - 1)]
        a[cy][cx] = '.'
        cy += dy
        cx += dx

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == 'O':
            res += y * 100 + x

print(res)