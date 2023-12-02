from sys import stdin

res = 0
for line in stdin:
    digits = [c for c in line if c.isdigit()]
    res += int(digits[0] + digits[-1])

print(res)
