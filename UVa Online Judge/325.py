import re

def solve():
    line = input().strip()

    if line == '*':
        return 0

    if re.match(r'^[+-]?\d+(\.\d+([eE][+-]?\d+)?|[eE][+-]?\d+)$', line):
        print(line, 'is legal.')
    else:
        print(line, 'is illegal.')
    return 1


while solve():
    pass
