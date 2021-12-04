from sys import stdin

ops = [line.split() for line in stdin]
y, x = 0, 0

for op, arg in ops:
    if op == 'forward':
        x += int(arg)
    elif op == 'down':
        y += int(arg)
    else:
        y -= int(arg)

print(y * x)
