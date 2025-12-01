from sys import stdin

value = 50
res = 0
for line in stdin:
    delta = int(line[1:])
    res += delta // 100
    delta = delta % 100 * (1 if line[0] == 'R' else -1)

    if value:
        res += (value + delta) >= 100 or (value + delta) <= 0
    value = (value + delta) % 100

print(res)
