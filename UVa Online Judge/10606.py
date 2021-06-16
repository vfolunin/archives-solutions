def solve():
    n = int(input())

    if not n:
        return 0

    l, r = 0, n + 1
    while l + 1 < r:
        m = (l + r) // 2
        if m * m <= n:
            l = m
        else:
            r = m

    print(l * l)
    return 1


while solve():
    pass
