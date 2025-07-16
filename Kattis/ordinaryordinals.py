n, mod = [int(_) for _ in input().split()]

print((pow(2, n - 1, mod) * 5 - 1) % mod if n > 1 else 2 % mod)