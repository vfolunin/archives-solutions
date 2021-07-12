def bin_pow(x, p, mod):
    if not p:
        return 1 % mod
    if p % 2:
        return bin_pow(x, p - 1, mod) * x % mod
    r = bin_pow(x, p // 2, mod)
    return r * r % mod


def solve():
    h, w = [int(_) for _ in input().split()]
    a = h * w // 2
    b = h * w - a

    mod = 10 ** 16 + 7
    res = bin_pow(a, b - 1, mod) * bin_pow(b, a - 1, mod) % mod

    print(res)


n = int(input())
for i in range(n):
    solve()
