from sys import stdin

base = -1

for line in stdin:
    if base == -1:
        base = int(line)
        count = [0 for i in range(base)]
        continue

    value = abs(int(line))

    has = [0 for i in range(base)]
    while value >= base:
        has[value % base] = 1
        value //= base
    has[value] = 1

    for i in range(base):
        count[i] += has[i]

res = count.index(max(count))

print(res if res < 10 else chr(ord('A') + res - 10))
