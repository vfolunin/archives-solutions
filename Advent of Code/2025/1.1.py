from sys import stdin

value = 50
res = 0
for line in stdin:
    value = (value + int(line[1:]) * (1 if line[0] == 'R' else -1)) % 100
    res += value == 0

print(res)
