def sqrt(n):
    l = 0
    r = n
    while l + 1 < r:
        m = l + (r - l) // 2
        if m * m < n:
            l = m
        else:
            r = m
    return l


n = int(input())

res = sqrt(n * 2)

print(res if res * (res + 1) // 2 == n else -1)