from sys import stdin


def diff(a, b):
    return sum(a[i] != b[i] for i in range(len(a)))


def is_mirror(a, j):
    w = min(j + 1, len(a[0]) - j - 1)
    diff_sum = 0
    for s in a:
        diff_sum += diff(s[j - w + 1:j + 1][::-1], s[j + 1:j + w + 1])
    return diff_sum == 1


def get_mirror(a):
    for j in range(len(a[0]) - 1):
        if is_mirror(a, j):
            return j
    return -1


def solve(a):
    res = get_mirror(a)
    if res != -1:
        return res + 1

    a = [[a[y][x] for y in range(len(a))] for x in range(len(a[0]))]
    res = get_mirror(a)
    if res != -1:
        return (res + 1) * 100


res = 0
a = []

for line in stdin:
    line = line.strip()
    if line:
        a.append(list(line))
    else:
        res += solve(a)
        a = []

print(res)
