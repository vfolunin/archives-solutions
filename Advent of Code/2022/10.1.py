from sys import stdin

timer = 0
value = 1
res = 0

for line in stdin:
    op, *arg = line.strip().split()

    if op == 'addx':
        timer += 1
        if timer % 40 == 20:
            res += timer * value

    timer += 1
    if timer % 40 == 20:
        res += timer * value

    if op == 'addx':
        value += int(arg[0])

print(res)
