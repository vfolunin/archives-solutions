def bin_pow(x, p, mod):
    if not p:
        return 1 % mod
    if p % 2:
        return bin_pow(x, p - 1, mod) * x % mod
    r = bin_pow(x, p // 2, mod)
    return r * r % mod


def rec(x, p, mod):
    if not p:
        return 1 % mod
    if p % 2 == 0:
        return (rec(x, p - 1, mod) + bin_pow(x, p, mod)) % mod
    r = rec(x, p // 2, mod)
    return r * (1 + bin_pow(x, p // 2 + 1, mod)) % mod


def solve():
    x, p, mod = [int(_) for _ in input().split()]

    print(rec(x, p, mod))


n = int(input())

for i in range(n):
    solve()