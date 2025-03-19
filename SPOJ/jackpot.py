from math import gcd


def lcm(*a):
    res = a[0]
    for i in range(1, len(a)):
        res = res // gcd(res, a[i]) * a[i]
    return res


def solve():
    input()
    res = lcm(*[int(_) for _ in input().split()])
    print(res if res <= 10 ** 9 else 'More than a billion.')


n = int(input())
for i in range(n):
    solve()
