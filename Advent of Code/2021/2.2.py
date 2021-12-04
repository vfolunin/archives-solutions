from sys import stdin

ops = [line.split() for line in stdin]
y, x, aim = 0, 0, 0

for op, arg in ops:
    if op == 'forward':
        x += int(arg)
        y += aim * int(arg)
    elif op == 'down':
        aim += int(arg)
    else:
        aim -= int(arg)

print(y * x)
