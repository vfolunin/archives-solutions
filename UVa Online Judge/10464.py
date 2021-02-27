def read(line):
    power = 1000 - (len(line) - line.index('.') if '.' in line else 1)
    return int(line.replace('.', '')) * 10 ** power


def write(n):
    negative = n < 0
    if negative:
        n = -n

    s = str(n)
    s = ('0' * (1000 - len(s))) + s
    s = s[:-999] + '.' + s[-999:]
    s = s.rstrip('0')
    if s[-1] == '.':
        s += '0'

    if negative:
        print('-', end='')
    print(s)


def solve():
    a, b = [read(_) for _ in input().split()]
    write(a + b)


n = int(input())
for i in range(n):
    solve()
