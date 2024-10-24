from math import lcm


def solve():
    a, b, c = [int(_) for _ in input().split()]

    print('YES' if lcm(a, b) == c else 'NO')


n = int(input())

for i in range(n):
    solve()
