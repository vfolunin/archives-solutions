from sys import stdin
from math import gcd

def solve(test, line):
    t, n = [int(_) for _ in line.split()]

    if t > 1:
        k = t ** n
        x = (k - 1) // (t - 1)
        d = gcd(k, x)
        x //= d
        k //= d
    else:
        x = n
        k = 1

    if test:
        print()
    print('X =', x)
    print('K =', k)


print('Dear GOD, Pardon Me')
for test, line in enumerate(stdin):
    solve(test, line)
