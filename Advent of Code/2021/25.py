from copy import deepcopy
from sys import stdin

a = [line.strip() for line in stdin]
h, w = len(a), len(a[0])

timer = 0
while True:
    update = 0
    next_a = [['.' for x in range(w)] for y in range(h)]

    for y in range(h):
        for x in range(w):
            if a[y][x] == '>':
                if a[y][(x + 1) % w] == '.':
                    update = 1
                    next_a[y][(x + 1) % w] = '>'
                else:
                    next_a[y][x] = '>'
            elif a[y][x] == 'v':
                next_a[y][x] = 'v'
    a = deepcopy(next_a)

    for y in range(h):
        for x in range(w):
            if a[y][x] == 'v':
                if a[(y + 1) % h][x] == '.':
                    update = 1
                    next_a[y][x] = '.'
                    next_a[(y + 1) % h][x] = 'v'
                else:
                    next_a[y][x] = 'v'
    a = deepcopy(next_a)

    timer += 1
    if not update:
        break

print(timer)
