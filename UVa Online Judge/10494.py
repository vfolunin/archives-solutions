from sys import stdin

def solve(line):
    sa, op, sb = line.split()
    a, b = int(sa), int(sb)
    print(a // b if op == '/' else a % b)

for line in stdin:
    solve(line)
