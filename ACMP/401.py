from math import comb

n, a, b = [int(_) for _ in input().split()]

res = 0
for ka in range(a + 1):
    for kb in range(b + 1):
        res += comb(n + ka - 1, ka) * comb(n + kb - 1, kb)

print(res)
