from functools import lru_cache

@lru_cache(maxsize=None)
def stirling1(n, k):
    if n == 0 and k == 0:
        return 1
    if n == 0 or k == 0:
        return 0
    return stirling1(n - 1, k - 1) - (n - 1) * stirling1(n - 1, k)


def solve():
    n, k = [int(_) for _ in input().split()]
    if not n and not k:
        return 0

    print(abs(stirling1(n, n - k)))
    return 1


while solve():
    pass
