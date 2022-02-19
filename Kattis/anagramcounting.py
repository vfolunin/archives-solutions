from collections import defaultdict
from math import factorial
from sys import stdin


def solve(line):
    count = defaultdict(int)
    for c in line:
        count[c] += 1

    res = factorial(len(line))
    for k in count.values():
        res //= factorial(k)

    print(res)


for line in stdin:
    solve(line.strip())
