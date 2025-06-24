def solve():
    a, b, c = [int(_) for _ in input().split()]
    if max(a, b, c) == 0:
        return 0

    if b - a == c - b:
        print('AP', c + c - b)
    else:
        print('GP', c * c // b)
    return 1


while solve():
    pass