from math import gcd
from sys import stdin


def lcm(*a):
    res = a[0]
    for i in range(1, len(a)):
        res = res // gcd(res, a[i]) * a[i]
    return res


for line in stdin:
    print(lcm(*[int(_) for _ in line.split()]))
