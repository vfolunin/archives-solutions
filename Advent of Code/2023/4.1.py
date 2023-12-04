from sys import stdin

res = 0

for line in stdin:
    a, b = [set(part.split()) for part in line.strip().split(':')[1].split('|')]
    common_count = len(a & b)
    if common_count:
        res += 2 ** (common_count - 1)

print(res)
