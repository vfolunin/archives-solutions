from collections import defaultdict
from sys import stdin

count = defaultdict(int)

for line in stdin:
    p1, p2 = line.split(' -> ')
    x1, y1 = [int(_) for _ in p1.split(',')]
    x2, y2 = [int(_) for _ in p2.split(',')]

    if x1 == x2 or y1 == y2:
        while 1:
            count[x1, y1] += 1
            if x1 == x2 and y1 == y2:
                break

            if x1 < x2:
                x1 += 1
            elif x1 > x2:
                x1 -= 1
            if y1 < y2:
                y1 += 1
            elif y1 > y2:
                y1 -= 1

res = 0
for k in count.values():
    res += k > 1

print(res)
