from math import prod
from sys import stdin

lines = [line[:-1] for line in stdin]

starts = []
for i in range(len(lines[-1])):
    if lines[-1][i] != ' ':
        starts.append(i)
starts.append(len(lines[-1]) + 2)

res = 0
for i in range(len(starts) - 1):
    values = []
    for x in range(starts[i], starts[i + 1] - 1):
        value = 0
        for y in range(len(lines) - 1):
            if lines[y][x] != ' ':
                value = value * 10 + int(lines[y][x])
        values.append(value)
    res += sum(values) if lines[-1][starts[i]] == '+' else prod(values)

print(res)
