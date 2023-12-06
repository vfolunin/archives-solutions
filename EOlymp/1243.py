from math import lcm


def solve():
    a = [int(_) for _ in input().split()]
    res = 1

    for value in a[1:]:
        res = lcm(res, value)

    print(res)


n = int(input())

for i in range(n):
    solve()