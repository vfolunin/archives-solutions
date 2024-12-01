from collections import defaultdict
from sys import stdin

a = []
count = defaultdict(int)
for line in stdin:
    a_value, b_value = [int(_) for _ in line.split()]
    a.append(a_value)
    count[b_value] += 1

res = 0
for value in a:
    res += value * count[value]

print(res)
