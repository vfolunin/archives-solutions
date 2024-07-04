def solve(test):
    x, p, m = [int(_) for _ in input().split()]
    if not x and not p and not m:
        return 0

    print('Case #{}: {}'.format(test, pow(x, p, 10 ** m)))
    return 1


test = 1
while solve(test):
    test += 1
