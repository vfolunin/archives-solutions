def solve():
    n = int(input())
    if n < 0:
        return 0

    if n < 10:
        print('1', n, sep='')
        return 1

    res = []
    for d in range(9, 1, -1):
        while n % d == 0:
            res.append(d)
            n //= d

    if n != 1:
        print('There is no such number.')
    else:
        print(''.join(str(_) for _ in res[::-1]))
    return 1


while solve():
    pass
