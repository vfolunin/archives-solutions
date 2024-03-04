h, w = [int(_) for _ in input().split()]

ways = [[0 for x in range(w)] for y in range(h)]
ways[0][0] = 1

for d in range(h + w - 1):
    y, x = d, 0
    while y >= 0:
        if 0 <= y < h and 0 <= x < w:
            for dy, dx in [(-1, 2), (1, 2), (2, -1), (2, 1)]:
                ty, tx = y + dy, x + dx
                if 0 <= ty < h and 0 <= tx < w:
                    ways[ty][tx] += ways[y][x]
        y -= 1
        x += 1

print(ways[h - 1][w - 1])
