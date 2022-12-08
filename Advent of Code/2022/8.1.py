from sys import stdin


def check_visibility_in_row(a):
    for i in range(len(a) - 1):
        if a[i] >= a[-1]:
            return 0
    return 1


def check_visibility(a, y, x):
    return (check_visibility_in_row([a[i][x] for i in range(y + 1)]) or
            check_visibility_in_row([a[i][x] for i in range(len(a) - 1, y - 1, -1)]) or
            check_visibility_in_row([a[y][i] for i in range(x + 1)]) or
            check_visibility_in_row([a[y][i] for i in range(len(a[0]) - 1, x - 1, -1)]))


a = [line.strip() for line in stdin]
res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        res += check_visibility(a, y, x)
print(res)
