from sys import stdin


def get_type(a, b):
    if a < b:
        return -1
    elif a == b:
        return 0
    else:
        return 1


def check(a):
    if get_type(a[0], a[1]) == 0:
        return 0

    for i in range(1, len(a)):
        delta = abs(a[i - 1] - a[i])
        if delta < 1 or delta > 3 or get_type(a[0], a[1]) != get_type(a[i - 1], a[i]):
            return 0

    return 1


res = 0

for line in stdin:
    a = [int(_) for _ in line.split()]
    res += check(a)

print(res)
