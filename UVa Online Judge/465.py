from sys import stdin

def check(value, name):
    if value >= 2 ** 31:
        print(name, 'too big')

def solve(line):
    if line[-1] == '\n':
        line = line[:-1]
    print(line)
    sa, op, sb = line.split()

    a, b = int(sa), int(sb)
    check(a, 'first number')
    check(b, 'second number')
    check(a + b if op == '+' else a * b, 'result')

for line in stdin:
    solve(line)
