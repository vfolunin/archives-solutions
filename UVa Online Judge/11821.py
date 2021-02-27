def read():
    line = input()
    power = 100 - (len(line) - line.index('.') if '.' in line else 1)
    return int(line.replace('.', '')) * 10 ** power


def write(n):
    negative = n < 0
    if negative:
        n = -n

    s = str(n)
    s = ('0' * (100 - len(s))) + s
    s = s[:-99] + '.' + s[-99:]
    s = s.rstrip('0').rstrip('.')

    if negative:
        print('-', end='')
    print(s)


def solve():
    sum = 0
    while 1:
        n = read()
        if not n:
            break
        sum += n
    write(sum)


n = int(input())
for i in range(n):
    solve()
