def solve():
    n = int(input())

    if not n:
        return 0

    pow = 1
    while (pow * 10) ** 2 <= n:
        pow *= 10

    res = pow
    while (res + pow) ** 2 <= n:
        res += pow

    print(res)
    return 1


while solve():
    pass
