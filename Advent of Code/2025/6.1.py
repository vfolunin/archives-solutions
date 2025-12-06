from math import prod
from sys import stdin

a = []
for line in stdin:
    a.append(line.strip().split())

res = 0
for x in range(len(a[0])):
    values = [int(a[y][x]) for y in range(len(a) - 1)]
    res += sum(values) if a[-1][x] == '+' else prod(values)

print(res)
