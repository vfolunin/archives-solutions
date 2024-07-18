from math import comb


def solve():
    n, k = [int(_) for _ in input().split()]
    print(comb(n, k))


n = int(input())
for i in range(n):
    solve()