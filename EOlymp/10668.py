from math import comb

h, w = [int(_) for _ in input().split()]

print(comb(h + w, h))