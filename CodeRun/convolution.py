h, w = [int(_) for _ in input().split()]
a = [[int(_) for _ in input().split()] for y in range(h)]

size = int(input())
b = [[int(_) for _ in input().split()] for y in range(size)]

res = [[0 for x in range(w - size + 1)] for y in range(h - size + 1)]
for y in range(h - size + 1):
    for x in range(w - size + 1):
        for by in range(size):
            for bx in range(size):
                res[y][x] += a[y + by][x + bx] * b[by][bx]

for row in res:
    print(*row)