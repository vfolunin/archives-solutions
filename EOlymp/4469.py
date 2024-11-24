from sys import set_int_max_str_digits


def multiply(a, b):
    res = [[0 for x in range(len(b[0]))] for y in range(len(a))]
    for y in range(len(a)):
        for x in range(len(b[0])):
            for i in range(len(a[0])):
                res[y][x] += a[y][i] * b[i][x]
    return res


def identity_matrix(size):
    return [[y == x for x in range(size)] for y in range(size)]


def power(m, p):
    if p == 0:
        return identity_matrix(len(m))
    if p % 2:
        return multiply(power(m, p - 1), m)
    r = power(m, p // 2)
    return multiply(r, r)


n = int(input())

set_int_max_str_digits(10 ** 5)
print(power([[0, 1], [1, 1]], n)[1][1])