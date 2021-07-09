from functools import lru_cache
from sys import stdin

@lru_cache(maxsize=None)
def rec(n, k):
    if n < k:
        return 0
    if n == k:
        return 1
    res = rec(n - 1, k)
    for zeros in range(1, k):
        res += rec(n - zeros - 1, k)
    res += 2 ** (n - k)
    return res


for line in stdin:
    n, k = [int(_) for _ in line.split()]
    print(rec(n, k))
