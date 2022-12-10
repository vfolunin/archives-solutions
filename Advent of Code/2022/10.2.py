from sys import stdin

timer = 0
value = 1
res = [['.' for x in range(40)] for y in range(6)]

for line in stdin:
    op, *arg = line.strip().split()

    if op == 'addx':
        if abs(timer % 40 - value) <= 1:
            res[timer // 40][timer % 40] = 'X'
        timer += 1

    if abs(timer % 40 - value) <= 1:
        res[timer // 40][timer % 40] = 'X'
    timer += 1

    if op == 'addx':
        value += int(arg[0])

print('\n'.join(''.join(row) for row in res))
