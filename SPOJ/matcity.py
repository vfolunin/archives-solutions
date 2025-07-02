from math import comb


def solve(test):
    x1, y1, x2, y2 = [int(_) for _ in input().split()]

    print(f'Case #{test}: {comb(x2 - x1 + y2 - y1, x2 - x1)}')


test_count = int(input())

for test in range(1, test_count + 1):
    solve(test)