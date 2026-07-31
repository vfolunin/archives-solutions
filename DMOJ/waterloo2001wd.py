from math import log10
from sys import stdin


def solve(line):
    t, a, b = [int(_) for _ in line.split()]

    print('({}^{}-1)/({}^{}-1)'.format(t, a, t, b), end=' ')

    if t == 1 or a % b or (a - b) * log10(t) > 99:
        print('is not an integer with less than 100 digits.')
    elif a == b:
        print(1)
    else:
        print((t ** a - 1) // (t ** b - 1))


for line in stdin:
    solve(line)
