def sqrt(n):
    l, r = 0, n
    while l + 1 < r:
        m = l + (r - l) // 2
        if m * m < n:
            l = m
        else:
            r = m
    return r


n = int(input())

print(sqrt(10 ** n) - sqrt(10 ** (n - 1)))