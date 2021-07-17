res = [1]
for i in range(1, 501):
    res.append(2 * (2 * i + 1) * res[i - 1] // (i + 1))


def solve(test):
    n = int(input())
    print('Case {}: {}'.format(test, res[n // 2 - 1]))


n = int(input())
for test in range(1, n + 1):
    solve(test)
