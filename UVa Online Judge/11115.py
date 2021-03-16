def solve():
    n, p = [int(_) for _ in input().split()]
    if not n and not p:
        return 0

    print(n ** p)
    return 1


while solve():
    pass
