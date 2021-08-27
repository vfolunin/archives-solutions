res = [[10 ** 100 for p in range(21)] for n in range(201)]
for n in range(201):
    res[n][3] = 2 ** n - 1
    for p in range(4, 21):
        if n < p:
            res[n][p] = max(0, 2 * n - 1)
        else:
            res[n][p] = min(2 * res[k][p] + res[n - k][p - 1] for k in range(1, n))


def solve(test):
    n, p = [int(_) for _ in input().split()]
    if not n and not p:
        return 0

    print('Case {}: {}'.format(test, res[n][p]))
    return 1


test = 1
while solve(test):
    test += 1
