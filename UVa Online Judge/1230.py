def bin_pow(x, n, mod):
    if n == 0:
        return 1 % mod
    if n % 2:
        return bin_pow(x, n - 1, mod) * x % mod
    r = bin_pow(x, n // 2, mod)
    return r * r % mod

n = int(input())
for i in range(n):
    x, n, mod = [int(_) for _ in input().split()]
    print(bin_pow(x, n, mod))
