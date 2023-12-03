from sys import stdin


def is_symbol(a, y, x):
    return 0 <= y < len(a) and 0 <= x < len(a[0]) and a[y][x] != '.' and not a[y][x].isdigit()


def has_neighbor_symbol(a, y, x):
    for dy in range(-1, 2):
        for dx in range(-1, 2):
            if is_symbol(a, y + dy, x + dx):
                return 1
    return 0


def get_value(a, y, x):
    res, has_symbol = 0, 0
    while x < len(a[0]) and a[y][x].isdigit():
        res = res * 10 + int(a[y][x])
        has_symbol |= has_neighbor_symbol(a, y, x)
        x += 1
    return res if has_symbol else 0


a = [line.strip() for line in stdin]

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x].isdigit() and (x == 0 or not a[y][x - 1].isdigit()):
            res += get_value(a, y, x)

print(res)
