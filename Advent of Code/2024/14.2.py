from sys import stdin


def dfs(a, y, x):
    a[y][x] = '#'
    for dy, dx in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
        ty, tx = y + dy, x + dx
        if 0 <= ty < len(a) and 0 <= tx < len(a[0]) and a[ty][tx] == 'X':
            dfs(a, ty, tx)


def check(a):
    cc_count = 0
    for y in range(len(a)):
        for x in range(len(a[0])):
            if a[y][x] == 'X':
                if cc_count < 200:
                    dfs(a, y, x)
                    cc_count += 1
                else:
                    return 0
    return 1


w, h = 101, 103
coords = []

for line in stdin:
    p, v = line.strip().split()
    x, y = [int(_) for _ in p.split('=')[1].split(',')]
    vx, vy = [int(_) for _ in v.split('=')[1].split(',')]
    coords.append([x, y, vx, vy])

for i in range(10 ** 6):
    a = [['.' for x in range(w)] for y in range(h)]
    for x, y, vx, vy in coords:
        a[y][x] = 'X'

    if check(a):
        print(i)
        for row in a:
            print(''.join(row))
        break

    for i in range(len(coords)):
        x, y, vx, vy = coords[i]
        coords[i] = [(x + vx) % w, (y + vy) % h, vx, vy]