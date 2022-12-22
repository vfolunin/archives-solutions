from sys import stdin


def parse_commands(line):
    path = [0]
    for c in line:
        if c.isdigit():
            path[-1] = path[-1] * 10 + int(c)
        else:
            path.append(c)
            path.append(0)
    return path


def read_input():
    a = [line.rstrip() for line in stdin]
    a, commands = a[:-2], parse_commands(a[-1])

    h = len(a) + 2
    w = max(len(line) for line in a) + 2

    a.insert(0, '')
    a.append('')
    for y in range(h):
        a[y] = ' ' + a[y] + ' ' * (w - 1 - len(a[y]))

    return a, commands


a, commands = read_input()

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]
y, x, d = 1, 1, 0
while a[y][x] == ' ':
    x += 1

for command in commands:
    if command == 'L':
        d = (d - 1) % len(dy)
    elif command == 'R':
        d = (d + 1) % len(dy)
    else:
        for i in range(command):
            ty = y + dy[d]
            tx = x + dx[d]

            while a[ty][tx] == ' ':
                ty = (ty + dy[d]) % len(a)
                tx = (tx + dx[d]) % len(a[0])

            if a[ty][tx] == '#':
                break
            else:
                y, x = ty, tx

print(1000 * y + 4 * x + d)
