from sys import stdin

w, h, t = 101, 103, 100
count = [0] * 4

for line in stdin:
    p, v = line.strip().split()
    x, y = [int(_) for _ in p.split('=')[1].split(',')]
    vx, vy = [int(_) for _ in v.split('=')[1].split(',')]

    x = (x + vx * t) % w
    y = (y + vy * t) % h

    count[0] += x < w // 2 and y < h // 2
    count[1] += x < w // 2 and y > h // 2
    count[2] += x > w // 2 and y < h // 2
    count[3] += x > w // 2 and y > h // 2

print(count[0] * count[1] * count[2] * count[3])