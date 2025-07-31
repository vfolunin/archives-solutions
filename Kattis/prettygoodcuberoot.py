from sys import stdin

for line in stdin:
    n = int(line)

    l, r = 0, 1
    while r ** 3 < n:
        r *= 2

    while l + 1 < r:
        m = l + (r - l) // 2
        if m ** 3 < n:
            l = m
        else:
            r = m

    print(l if n - l ** 3 < r ** 3 - n else r)
