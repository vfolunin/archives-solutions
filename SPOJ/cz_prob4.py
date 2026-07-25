from math import comb


def solve():
    n, k = [int(_) for _ in input().split()]

    print(sum(comb(k, i) for i in range(n + 1)))


test_count = int(input())
for test in range(test_count):
    solve()