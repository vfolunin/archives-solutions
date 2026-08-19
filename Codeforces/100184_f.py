from math import lcm


def sum_to(to):
    return (1 + to) * to // 2


def sum_d(to, d):
    return sum_to(to // d) * d


n, a, b = [int(_) for _ in input().split()]
n -= 1

print((sum_d(n, a) + sum_d(n, b) - sum_d(n, lcm(a, b))) % (10 ** 9 + 7))
