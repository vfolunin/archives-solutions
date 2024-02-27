from math import comb

n, k = [int(_) for _ in input().split()]

print(comb(n // 5 + k, k))
