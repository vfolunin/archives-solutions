from sys import stdin


def get_numbers(line):
    res = []
    for part in line.split():
        digits = ''.join(c for c in part if c.isdigit())
        if digits != '':
            res.append(int(digits))
    return res


def solve(ax, ay, bx, by, x, y):
    res = 10 ** 9
    for ka in range(x // ax + 1):
        kb = (x - ka * ax) // bx
        if ka * ax + kb * bx == x and ka * ay + kb * by == y:
            res = min(res, 3 * ka + kb)
    return res if res != 10 ** 9 else 0


a = [line.strip() for line in stdin]

res = 0
for i in range(0, len(a), 4):
    ax, ay = get_numbers(a[i])
    bx, by = get_numbers(a[i + 1])
    x, y = get_numbers(a[i + 2])
    res += solve(ax, ay, bx, by, x, y)

print(res)