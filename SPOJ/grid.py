from math import comb


def solve():
    h, w, mod = [int(_) for _ in input().split()]

    print(comb(h + w, w) % mod)


n = int(input())
for i in range(n):
    solve()