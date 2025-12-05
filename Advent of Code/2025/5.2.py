from sys import stdin

events = []
for line in stdin:
    line = line.strip()
    if '-' in line:
        l, r = [int(_) for _ in line.split('-')]
        events.append([l, 1])
        events.append([r, -1])

events.sort(key=lambda event: (event[0], -event[1]))

start = -1
count = 0
res = 0
for coord, delta in events:
    count += delta
    if count == 1 and delta == 1:
        start = coord
    elif count == 0 and delta == -1:
        res += coord - start + 1
print(res)
