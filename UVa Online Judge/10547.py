def bin_pow(x, p, mod):
    if not p:
        return 1 % mod
    if p % 2:
        return bin_pow(x, p - 1, mod) * x % mod
    r = bin_pow(x, p // 2, mod)
    return r * r % mod


def solve(test):
    x, p, m = [int(_) for _ in input().split()]
    if not x and not p and not m:
        return 0

    print('Case #{}: {}'.format(test, bin_pow(x, p, 10 ** m)))
    return 1


test = 1
while solve(test):
    test += 1
