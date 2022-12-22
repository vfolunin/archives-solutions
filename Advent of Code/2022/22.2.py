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


def yx2c(y, x):
    if y <= 50:
        if x <= 100:
            return 'A', y - 1, x - 51
        else:
            return 'B', y - 1, x - 101
    elif y <= 100:
        return 'C', y - 51, x - 51
    elif y <= 150:
        if x <= 50:
            return 'D', y - 101, x - 1
        else:
            return 'E', y - 101, x - 51
    else:
        return 'F', y - 151, x - 1


def c2yx(c, y, x):
    if c == 'A':
        return y + 1, x + 51
    elif c == 'B':
        return y + 1, x + 101
    elif c == 'C':
        return y + 51, x + 51
    elif c == 'D':
        return y + 101, x + 1
    elif c == 'E':
        return y + 101, x + 51
    else:
        return y + 151, x + 1


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
            c, cy, cx = yx2c(y, x)
            tc, tcy, tcx, td = c, cy + dy[d], cx + dx[d], d

            if tcy == -1:
                if c == 'A':
                    tc, tcy, tcx, td = 'F', tcx, 0, 0
                elif c == 'B':
                    tc, tcy, tcx, td = 'F', 49, tcx, 3
                elif c == 'C':
                    tc, tcy, tcx, td = 'A', 49, tcx, 3
                elif c == 'D':
                    tc, tcy, tcx, td = 'C', tcx, 0, 0
                elif c == 'E':
                    tc, tcy, tcx, td = 'C', 49, tcx, 3
                else:
                    tc, tcy, tcx, td = 'D', 49, tcx, 3
            elif tcy == 50:
                if c == 'A':
                    tc, tcy, tcx, td = 'C', 0, tcx, 1
                elif c == 'B':
                    tc, tcy, tcx, td = 'C', tcx, 49, 2
                elif c == 'C':
                    tc, tcy, tcx, td = 'E', 0, tcx, 1
                elif c == 'D':
                    tc, tcy, tcx, td = 'F', 0, tcx, 1
                elif c == 'E':
                    tc, tcy, tcx, td = 'F', tcx, 49, 2
                else:
                    tc, tcy, tcx, td = 'B', 0, tcx, 1
            elif tcx == -1:
                if c == 'A':
                    tc, tcy, tcx, td = 'D', 49 - tcy, 0, 0
                elif c == 'B':
                    tc, tcy, tcx, td = 'A', tcy, 49, 2
                elif c == 'C':
                    tc, tcy, tcx, td = 'D', 0, tcy, 1
                elif c == 'D':
                    tc, tcy, tcx, td = 'A', 49 - tcy, 0, 0
                elif c == 'E':
                    tc, tcy, tcx, td = 'D', tcy, 49, 2
                else:
                    tc, tcy, tcx, td = 'A', 0, tcy, 1
            elif tcx == 50:
                if c == 'A':
                    tc, tcy, tcx, td = 'B', tcy, 0, 0
                elif c == 'B':
                    tc, tcy, tcx, td = 'E', 49 - tcy, 49, 2
                elif c == 'C':
                    tc, tcy, tcx, td = 'B', 49, tcy, 3
                elif c == 'D':
                    tc, tcy, tcx, td = 'E', tcy, 0, 0
                elif c == 'E':
                    tc, tcy, tcx, td = 'B', 49 - tcy, 49, 2
                else:
                    tc, tcy, tcx, td = 'E', 49, tcy, 3

            ty, tx = c2yx(tc, tcy, tcx)
            if a[ty][tx] == '#':
                break
            y, x, d = ty, tx, td

print(1000 * y + 4 * x + d)
