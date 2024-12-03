from sys import stdin
from re import findall

enabled = 1
res = 0
for line in stdin:
    for op in findall('do\(\)|don\'t\(\)|mul\(\d+,\d+\)', line):
        if op == 'do()':
            enabled = 1
        elif op == 'don\'t()':
            enabled = 0
        elif enabled:
            a, b = [int(_) for _ in op[4:-1].split(',')]
            res += a * b

print(res)
