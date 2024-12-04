from sys import stdin

a = [line.strip() for line in stdin]

res = 0
for y in range(1, len(a) - 1):
    for x in range(1, len(a[0]) - 1):
        if a[y][x] != 'A':
            continue

        ok = 1
        for dx in [-1, 1]:
            ty1 = y - 1
            tx1 = x - dx
            ty2 = y + 1
            tx2 = x + dx
            ok &= sorted([a[ty1][tx1], a[ty2][tx2]]) == ['M', 'S']
        res += ok

print(res)
