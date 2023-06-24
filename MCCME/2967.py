from math import sqrt


def find(limit):
    l, r = 1, limit
    while l + 1 < r:
        m = l + (r - l) // 2
        if sqrt(m * m) == m:
            l = m
        else:
            r = m
    return r


res = 10 ** 20

while 1:
    r = find(res + 1)
    if res == r:
        break
    res = r

print(res)
