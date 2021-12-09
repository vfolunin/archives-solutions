from sys import stdin

a = [line.strip() for line in stdin]
h, w = len(a), len(a[0])

risk_level_sum = 0
for y in range(h):
    for x in range(w):
        low_point = 1
        for dy, dx in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            ty, tx = y + dy, x + dx
            if 0 <= ty < h and 0 <= tx < w:
                low_point &= a[y][x] < a[ty][tx]
        if low_point:
            risk_level_sum += int(a[y][x]) + 1

print(risk_level_sum)
