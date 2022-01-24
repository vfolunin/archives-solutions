def solve():
    n = int(input())

    if not n:
        return 0

    n, p, res = n - 1, 0, []
    while n:
        if n % 2:
            res.append(str(3 ** p))
        n //= 2
        p += 1

    if len(res):
        print('{', ', '.join(res), '}')
    else:
        print('{ }')
    return 1


while solve():
    pass
