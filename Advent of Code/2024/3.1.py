from sys import stdin
from re import findall

res = 0
for line in stdin:
    for a, b in findall('mul\((\d+),(\d+)\)', line):
        res += int(a) * int(b)

print(res)
