from sys import stdin

points = [[int(_) for _ in line.strip().split(',')] for line in stdin]

res = 0
for a in points:
    for b in points:
        res = max(res, (abs(a[0] - b[0]) + 1) * (abs(a[1] - b[1]) + 1))

print(res)
