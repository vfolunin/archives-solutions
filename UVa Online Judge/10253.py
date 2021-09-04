def c(n, m):
    res = 1
    for i in range(n, n - m, -1):
        res *= i
    for i in range(1, m + 1):
        res //= i
    return res


count = [0 for _ in range(31)]
res = [0, 1]


def rec(n, start):
    global count, res

    if not n:
        p = 1
        for i in range(len(count)):
            if count[i]:
                p *= c(res[i] + count[i] - 1, count[i])
        res[-1] += p
        return

    for i in range(min(start, n), 0, -1):
        count[i] += 1
        rec(n - i, i)
        count[i] -= 1


for i in range(2, 31):
    res.append(0)
    rec(i, i - 1)
for i in range(2, 31):
    res[i] *= 2


def solve():
    n = int(input())

    if not n:
        return 0

    print(res[n])
    return 1


while solve():
    pass
