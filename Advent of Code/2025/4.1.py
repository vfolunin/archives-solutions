from sys import stdin

a = [line.strip() for line in stdin]

dy = [-1, -1, -1, 0, 1, 1, 1, 0]
dx = [-1, 0, 1, 1, 1, 0, -1, -1]
res = 0

for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] != '@':
            continue

        neighbor_count = 0
        for d in range(len(dy)):
            ty = y + dy[d]
            tx = x + dx[d]
            neighbor_count += 0 <= ty < len(a) and 0 <= tx < len(a[0]) and a[ty][tx] == '@'

        res += neighbor_count < 4

print(res)
